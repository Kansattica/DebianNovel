#include <string>
#include <string_view>
#include <algorithm>
#include <iostream>

static constexpr std::string_view main_body = "Why do people keep reading the \"X\" novel. Is it because women will literally install Debian?";
static constexpr std::string_view terminal = "Women will literally install Debian";
static constexpr char pump_char = 'X';
static constexpr size_t target_word_count = 50000;

template <typename T>
static constexpr size_t word_count(const T& str) noexcept
{
	return std::count(str.begin(), str.end(), ' ') + 1;
}

static constexpr void replace_pump_char_with(std::string& novel, std::string_view new_text) noexcept
{
	novel.replace(novel.find(pump_char), 1, new_text);
}

int main()
{
	std::string novel = std::string{main_body};

	while (novel.length() < (target_word_count - 1 + terminal.length()))
	{
		replace_pump_char_with(novel, main_body);
	}

	replace_pump_char_with(novel, terminal);

	std::cout << novel;
}
