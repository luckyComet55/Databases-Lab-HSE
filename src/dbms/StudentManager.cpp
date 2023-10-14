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
                std::cout << file_entry.path() << std::endl;
                auto filename = file_entry.path().stem().string();
                containers.emplace_back(file_entry.path(), fields.size(), filename);
            }
        }

        std::pair<db::meta::TransactionStatus, std::vector<std::string>> student_manager::find_record(
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

            if (id == "") {
                std::vector<std::string> res;
                for (int i = 0; i < containers.size(); ++i) {
                    auto ent = containers[i].get();
                    if (!ent.first) {
                        return {db::meta::TransactionStatus::FAIL_ON_INTERNAL, {}};
                    }
                    
                    bool eq = true;
                    for (int i = 0; i < fields_where.size(); ++i) {
                        std::cout << vals_where[i] << " <-> " << ent.second[fields_where[i]] << '\n';
                        eq = eq && (ent.second[fields_where[i]] == vals_where[i]);
                    }

                    if (!eq) {
                        continue;
                    }

                    std::string full_ent = ent.second[0];
                    for (int i = 1; i < ent.second.size(); ++i) {
                        full_ent.append(ent.second[i]);
                    }
                    res.push_back(full_ent);
                }

                if (res.size() != 0) {
                    return {db::meta::TransactionStatus::SUCCESS, res};
                }
            } else {
                for (int i = 0; i < containers.size(); ++i) {
                    if (containers[i].get_container_id() == id) {
                        auto res = containers[i].get();
                        if (!res.first) {
                            return {db::meta::TransactionStatus::FAIL_ON_INTERNAL, {}};
                        }
                        std::string full_ent = res.second[0];
                        for (int i = 1; i < res.second.size(); ++i) {
                            full_ent.append(res.second[i]);
                        }
                        return {db::meta::TransactionStatus::SUCCESS, {full_ent}};
                    }
                }
            }
            return {db::meta::TransactionStatus::NOT_FOUND, {}};
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
    }
}
