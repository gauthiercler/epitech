#ifndef CPP_RTYPE_MENU_UTILS_HPP
# define CPP_RTYPE_MENU_UTILS_HPP

#include <iostream>
#include <client/ImGui/imgui.h>
#include <packet/LobbyEntryPacket.hpp>

namespace rtype {
	namespace menu {
		namespace GUI {

		  template<class T, size_t N>
		  static std::string new_string(const std::array<T, N> &str) {
			  std::string ret;
			  for (auto character = str.begin();
				   *character != '\0'; ++character)
				  ret.append(1u, *character);
			  return ret;

		  }

		  static float getHorizontalTextPosition(const std::string &text) {
			  return (ImGui::GetWindowWidth() / 2) -
					 (ImGui::CalcTextSize(text.data()).x / 2);
		  }

		  template<typename F>
		  static void createButton(const std::string &name,
								   F callback,
								   const ImVec2 &size = ImVec2(0, 0),
								   const ImVec2 &position = ImVec2(0, 0)) {
			  ImGui::SetCursorPos(position.x == -1
								  ? ImVec2(
					  ImGui::GetWindowWidth() / 2 - size.x / 2, position.y)
								  : position
			  );
			  if (ImGui::Button(name.c_str(), size)) {
				  callback();
			  }
		  }

		  static auto vector_getter = [](void *vec, int idx,
										 const char **out_text) {
			  auto &vector = *static_cast<std::vector<std::string> *>(vec);
			  if (idx < 0 ||
				  idx >= static_cast<int>(vector.size())) { return false; }
			  *out_text = vector.at(idx).c_str();
			  return true;
		  };


		  static bool createListBox(const char *label, int *currIndex, std::vector<std::string> &values) {
			  if (values.empty()) { return false; }
			  return ImGui::ListBox(label, currIndex, vector_getter,
							 static_cast<void *>(&values), values.size());
		  }
		}
	}
}

#endif /* !CPP_RTYPE_MENU_UTILS_HPP*/
