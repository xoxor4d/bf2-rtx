#include "std_include.hpp"

#define VA_BUFFER_COUNT		64
#define VA_BUFFER_SIZE		65536

namespace utils
{
	int try_stoi(const std::string& str, const int& default_return_val)
	{
		int ret = default_return_val;

		try
		{
			ret = std::stoi(str);
		}
		catch (const std::invalid_argument)
		{ }

		return ret;
	}

	float try_stof(const std::string& str, const float& default_return_val)
	{
		float ret = default_return_val;

		try
		{
			ret = std::stof(str);
		}
		catch (const std::invalid_argument)
		{ }

		return ret;
	}

	bool starts_with(std::string_view haystack, std::string_view needle)
	{
		return (haystack.size() >= needle.size() && !strncmp(needle.data(), haystack.data(), needle.size()));
	}

	bool string_contains(const std::string_view& s1, const std::string_view s2)
	{
		const auto it = s1.find(s2);
		if (it != std::string::npos)
		{
			return true;
		}

		return false;
	}

	void replace_all(std::string& source, const std::string_view& from, const std::string_view& to)
	{
		std::string new_string;
		new_string.reserve(source.length());  // avoids a few memory allocations

		std::string::size_type last_pos = 0;
		std::string::size_type findPos;

		while (std::string::npos != (findPos = source.find(from, last_pos)))
		{
			new_string.append(source, last_pos, findPos - last_pos);
			new_string += to;
			last_pos = findPos + from.length();
		}

		// Care for the rest after last occurrence
		new_string += source.substr(last_pos);

		source.swap(new_string);
	}

	bool erase_substring(std::string& base, const std::string& replace)
	{
		if (const auto it = base.find(replace);
			it != std::string::npos)
		{
			base.erase(it, replace.size());
			return true;
		}

		return false;
	}

	std::string str_to_lower(std::string input)
	{
		std::ranges::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
		return input;
	}

	std::string convert_wstring(const std::wstring& wstr)
	{
		std::string result;
		result.reserve(wstr.size());

		for (const auto& chr : wstr)
		{
			result.push_back(static_cast<char>(chr));
		}

		return result;
	}

	const char* va(const char* fmt, ...)
	{
		static char g_vaBuffer[VA_BUFFER_COUNT][VA_BUFFER_SIZE];
		static int g_vaNextBufferIndex = 0;

		va_list ap;
		va_start(ap, fmt);
		char* dest = g_vaBuffer[g_vaNextBufferIndex];
		vsnprintf(g_vaBuffer[g_vaNextBufferIndex], VA_BUFFER_SIZE, fmt, ap);
		g_vaNextBufferIndex = (g_vaNextBufferIndex + 1) % VA_BUFFER_COUNT;
		va_end(ap);
		return dest;
	}

	void extract_integer_words(const std::string_view& str, std::vector<int>& integers, bool check_for_duplicates)
	{
		std::stringstream ss;

		//Storing the whole string into string stream
		ss << str;

		// Running loop till the end of the stream
		std::string temp;
		int found;

		while (!ss.eof())
		{
			// extracting word by word from stream 
			ss >> temp;

			// Checking the given word is integer or not
			if (std::stringstream(temp) >> found)
			{
				if (check_for_duplicates)
				{
					// check if we added the integer already
					if (std::find(integers.begin(), integers.end(), found) == integers.end())
					{
						// new integer
						integers.push_back(found);
					}
				}

				else
				{
					//cout << found << " ";
					integers.push_back(found);
				}
			}

			// To save from space at the end of string
			temp = "";
		}
	}
}
