/**
 * Taiga
 * Copyright (C) 2010-2024, Eren Okka
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "anime_db.hpp"
#include "compat/anime.hpp"
#include "compat/settings.hpp"

namespace anime {

QList<Anime> readDatabase() {
  return compat::v1::read_anime_database("./data/v1/db/anime.xml");
}

QList<ListEntry> readListEntries() {
  const auto settings = compat::v1::read_settings("./data/v1/settings.xml");
  const auto userDir = u"%1@%2"_qs.arg(settings["username"]).arg(settings["service"]);
  return compat::v1::read_list_entries(u"./data/v1/user/%1/anime.xml"_qs.arg(userDir));
}

}  // namespace anime
