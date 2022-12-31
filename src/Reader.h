#pragma once

#include <iostream>
#include <fstream>


class Reader {
private:
	std::string m_Filename;
	std::fstream m_Stream;
	std::string m_Text;

public:
	Reader(std::string filename)
		:m_Filename(filename)
	{
		m_Stream.open(m_Filename, std::ios::in);
		if (!m_Stream) {
			std::cout << "[FILE NOT FOUND]";
		}
		else {
			char ch;
			while (1) {
				m_Stream >> ch;
				if (m_Stream.eof()) break;
				m_Text += ch;
			}
		}
		m_Stream.close();
	}

	std::string getText() {
		return m_Text;
	}

	std::string getName() {
		return m_Filename;
	}
};