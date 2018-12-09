#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <random>

CustomExpressionEvaluator::CustomExpressionEvaluator()
{
}


CustomExpressionEvaluator::~CustomExpressionEvaluator()
{
}

double CustomExpressionEvaluator::calculate()
{
	double* tmp_pArray = getpArray();
	int tmp_operandlenght = getoperandsLenght();
	double answer = *tmp_pArray;
	double answer_tmp = *tmp_pArray;

	for (int i = 1; i < tmp_operandlenght; i++)
	{
		if (i % 2 == 0)
		{
			answer_tmp = *(tmp_pArray + i);
			answer_tmp /= i + 1;
			answer += answer_tmp;
			continue;
		}
		else
			answer_tmp = *(tmp_pArray + i);
			answer_tmp /= i + 1;
			answer -= answer_tmp;
	}

	return answer;
}

void CustomExpressionEvaluator::logToScreen()
{
	int tmp_operandlenght = getoperandsLenght();
	double* tmp_pArray = getpArray();


	for (int i = 0; i < tmp_operandlenght; i++)
	{
		if ((i + 1) == tmp_operandlenght)
			std::cout << *(tmp_pArray + i);
		else
			std::cout << *(tmp_pArray + i) << ", ";

	}
	std::cout << " : ";
	for (int i = 0; i < tmp_operandlenght; i++)
	{
		if (i == 0)
		{
			if (*(tmp_pArray + i) >= 0)
				std::cout << *(tmp_pArray + i);
			if (tmp_operandlenght != i + 1)
				std::cout << "-";
			continue;
		}
			std::cout << "(" << *(tmp_pArray + i) << "/" << i + 1 << ")";
			if (tmp_operandlenght != i + 1)
				if (i % 2 == 0){      
					std::cout << "-"; ;
			}
				else
			std::cout << "+";
	}
}

void CustomExpressionEvaluator::logToFile(const std::string& filename)
{
	int tmp_operandlenght = getoperandsLenght();
	double* tmp_pArray = getpArray();

	std::fstream fout(filename, std::ios::app);

	for (int i = 0; i < tmp_operandlenght; i++)
	{
		if ((i + 1) == tmp_operandlenght)
		{
			fout << *(tmp_pArray + i);
		}
		else
		{
			fout << *(tmp_pArray + i) << ", ";
		}

	}
	fout << " : ";
	for (int i = 0; i < tmp_operandlenght; i++)
	{
		
			if (i == 0)
			{
				if (*(tmp_pArray + i) >= 0)
					fout << *(tmp_pArray + i);
				if (tmp_operandlenght != i + 1)
					fout << "-";
				continue;
			}
			fout << "(" << *(tmp_pArray + i) << "/" << i + 1 << ")";
			if (tmp_operandlenght != i + 1)
				if (i % 2 == 0) {
					fout << "-"; ;
				}
				else
					fout << "+";
		
	}
	fout << std::endl << std::endl;
	fout.close();
}

void CustomExpressionEvaluator::shuffle()
{
	int olen = getoperandsLenght();
	double* pArray = getpArray();
			for (int k = 0; k < olen - 1; k++)
			{
				for (int j = k + 1; j < olen; j++)
				{
					if (*(pArray + k) < *(pArray + j))
						std::swap(*(pArray + k), *(pArray + j));
				}
			}
		
	

}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j)
{
	double* pArray = getpArray();
	std::swap(*(pArray + i), *(pArray + j));
}