#include "ExpressionEvaluator.h"

#include "Summator.h"
#include "Multiplier.h"
#include "CustomExpressionEvaluator.h"
#include "ILoggable.h"
#include "IShuffle.h"

#include <iostream>

int main()
{
	ExpressionEvaluator* evaluators[3];

	evaluators[0] = new Multiplier();
	double Multiplier_operands[] = { -4.5, 2, 3, -10 };
	evaluators[0]->setOperands(Multiplier_operands, 4);
	

	evaluators[1] = new CustomExpressionEvaluator();
	double custom_operands[] = { 5, 16, -3, 10, 12, 3 };
	evaluators[1]->setOperands(custom_operands, 6);


	evaluators[2] = new Summator();
	evaluators[2]->setOperand(0, 39.1);
	evaluators[2]->setOperand(1, -12.7);

	

	for (int i = 0; i < 3; i++)
	{
		evaluators[i]->logToFile("Проект4.log");
		evaluators[i]->logToScreen();
		std::cout << "\n-> " << evaluators[i]->calculate() << std::endl << std::endl;
	}
	std::cout << "\nAnd now Shuffle \n";
	for (int i = 0; i < 3; i++)
	{
		IShuffle* loga = dynamic_cast<IShuffle*>(evaluators[i]);

		if (loga)
		{
			loga->shuffle();
			evaluators[i]->logToScreen();
			std::cout << "\n-> " << evaluators[i]->calculate() << std::endl << std::endl;
		}
	} 



	delete evaluators[0];
	delete evaluators[1];
	delete evaluators[2];

	//return 0;
	system("pause");
}