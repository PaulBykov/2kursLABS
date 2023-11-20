#pragma once
#include "D:/help/feat.hpp"


namespace Error {
	struct Error : exception {
		unsigned short code;
		string message;

		map<int, string> ErrorCodes = {
		{1, "������������ �������� ������"},
		{2, "����������� ������"},
		{3, "�������� ���������� �������"},
		{4, "������������ �����"}

		};

		Error(unsigned short code) {
			this->code = code;
			this->message = ErrorCodes[code];
		}
	};

}

