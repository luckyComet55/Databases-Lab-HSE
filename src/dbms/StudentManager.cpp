#include <vector>
#include <string>
#include <utility>
#include <filesystem>
#include <iostream>

#include "Container.hpp"
#include "../Types/Meta/Constants.hpp"
#include "../Types/Meta/Uuid.hpp"
#include "StudentManager.hpp"

namespace db {

    namespace fs {

        student_manager::student_manager(const std::filesystem::path& root_dir, bool is_new) : root_dir(root_dir) {
            if (is_new) {
                return;
            }

            for (auto const& file_entry : std::filesystem::directory_iterator{root_dir}) {
                auto filename = file_entry.path().stem().string();
                containers.emplace_back(file_entry.path(), fields.size(), filename);
            }
        }

        db::meta::TransactionStatus student_manager::delete_record(
            const std::vector<std::string>& vals_where,
            const std::vector<int>& fields_where
        ) {
            auto check_records = find_containers_where_clause(vals_where, fields_where);
            if(!check_records.first) {
                return db::meta::TransactionStatus::FAIL_ON_INTERNAL;
            }

            for (auto i : check_records.second) {
                bool res = std::filesystem::remove(containers[i].get_filepath());
                if (!res) {
                    return db::meta::TransactionStatus::FAIL_ON_INTERNAL;
                }
                containers.erase(containers.begin() + i);
            }

            return db::meta::TransactionStatus::SUCCESS;
        }

        std::pair<db::meta::TransactionStatus, std::vector<std::string>> student_manager::find_record(
            const std::vector<std::string>& vals_where,
            const std::vector<int>& fields_where
        ) {

            auto res = find_containers_where_clause(vals_where, fields_where);
            if (!res.first) {
                return {db::meta::TransactionStatus::FAIL_ON_INTERNAL, {}};
            }

            std::vector<std::string> ret;
            for (auto i : res.second) {
                auto res1 = containers[i].get();
                if (!res1.first) {
                    return {db::meta::TransactionStatus::FAIL_ON_INTERNAL, {}};
                }
                std::string full_ent = res1.second[0] + " ";
                for (int i = 1; i < res1.second.size(); ++i) {
                    full_ent.append(res1.second[i] + " ");
                }
                ret.push_back(full_ent);
            }

            if (ret.size() == 0) {
                return {db::meta::TransactionStatus::NOT_FOUND, {}};
            }
            return {db::meta::TransactionStatus::SUCCESS, ret};
        }

        db::meta::TransactionStatus student_manager::insert_record(const std::vector<std::string>& entity) {
            auto check_exists = find_record(entity, {1, 2, 3});
            if (check_exists.first == db::meta::TransactionStatus::SUCCESS) {
                return db::meta::TransactionStatus::FAIL_ON_CONSTRAINT;
            } else if (check_exists.first != db::meta::TransactionStatus::NOT_FOUND) {
                return check_exists.first;
            }

            std::string id = db::meta::uuid::generate_uuid();
            std::string filename = id + ".txt";
            auto filepath = root_dir / filename;
            containers.emplace_back(filepath, fields.size(), id);
            bool res = containers[containers.size() - 1].insert(entity);
            if (!res) {
                return db::meta::TransactionStatus::FAIL_ON_INTERNAL;
            }
            return db::meta::TransactionStatus::SUCCESS;
        }

        std::pair<bool, std::vector<int>> student_manager::find_containers_where_clause(
            const std::vector<std::string>& vals_where,
            const std::vector<int>& fields_where
        ) {
            std::string id = "";
            for (int i = 0; i < fields_where.size(); ++i) {
                if (fields_where[i] == 0) {
                    id = vals_where[i];
                    break;
                }
            }
            std::vector<int> conts;
            if (id == "") {
                for (int i = 0; i < containers.size(); ++i) {
                    auto ent = containers[i].get();
                    if (!ent.first) {
                        return {false, {}};
                    }
                    
                    bool eq = true;
                    for (int i = 0; i < fields_where.size(); ++i) {
                        eq = eq && (ent.second[fields_where[i]] == vals_where[i]);
                    }

                    if (!eq) {
                        continue;
                    }
                    conts.push_back(i);
                }
            } else {
                for (int i = 0; i < containers.size(); ++i) {
                    if (containers[i].get_container_id() == id) {
                        conts.push_back(i);
                    }
                }
            }
            return {true, conts};
        }
    }
}
