#include <iostream>
#include <cstdio>
#include "graph.h"
#include "io.h"
#include "file.h"
#include "StMark.h"


/// <summary>
/// Tries to open the students' mark data file. 
/// If successful it will print a report based on the 
/// date in the file.
/// </summary>
/// <param name="filename">, holds the data file name</param>
/// <returns>True if the date files is opened succesfully, 
/// otherwise returns false</returns>

namespace seneca {
	using namespace std;
	struct StMark marks[MAX_NO_RECS];
	struct StMark tempMark[MAX_NO_RECS];
	char file[30] = {};
	int range[10] = { 0 };
	int nbr_mark = readMarks(marks);

	bool printReport(const char* file) {
		
		if (openFile(file))
		{
			for (int i = 0; i <nbr_mark; i++)
			{
				if (marks[i].mark >= 0 && marks[i].mark <= 10)
				{
					range[9]++;
				}

				else if (marks[i].mark >= 11 && marks[i].mark <= 20)
				{
					range[8]++;
				}

				else if (marks[i].mark >= 21 && marks[i].mark <= 30)
				{
					range[7]++;
				}

				else if (marks[i].mark >= 31 && marks[i].mark <= 40)
				{
					range[6]++;
				}

				else if (marks[i].mark >= 41 && marks[i].mark <= 50)
				{
					range[5]++;
				}

				else if (marks[i].mark >= 51 && marks[i].mark <= 60)
				{
					range[4]++;
				}

				else if (marks[i].mark >= 61 && marks[i].mark <= 70)
				{
					range[3]++;
				}


				else if (marks[i].mark >= 71 && marks[i].mark <= 80)
				{
					range[2]++;
				}

				else if (marks[i].mark >= 81 && marks[i].mark <= 90)
				{
					range[1]++;
				}

				else if (marks[i].mark >= 91 && marks[i].mark <= 100)
				{
					range[0]++;
				}
			}
			

			for (int i = 0; i < nbr_mark - 1; i++)
			{
				for (int j = 0; j < nbr_mark - 1 - i; j++)
				{
					if (marks[j].mark < marks[j + 1].mark) {

						tempMark[j] = marks[j];
						marks[j] = marks[j + 1];
						marks[j + 1] = tempMark[j];
					}
				}
			}

			for (int i = 0; i < nbr_mark; i++)
			{
				printInt(i+1, 3);
				cout << ": [";
				printInt(marks[i].mark, 3);
				cout << "] " << marks[i].name << marks[i].surname;
				
			}


			printGraph(range, 10, "Students' mark distribution");
			closeFile();
		}

		return openFile(file);

	}

}
