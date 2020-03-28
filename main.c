#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

#define maxNameBufferSize 255

char maxNameBuffer[255];
typedef struct
{
	int age;
	char* name;
} Person;
void inputPersonFromFile(Person* p, FILE* f)
{
	fscanf_s(f, "%d", &(p->age));
	fgets(maxNameBuffer, maxNameBufferSize, f);

	int sizeOfBuffer = strlen(maxNameBuffer);
	p->name = (char*)malloc((sizeOfBuffer + 1) * sizeof(char));

	maxNameBuffer[sizeOfBuffer - 1] = 0;
	strcpy_s(p->name, sizeOfBuffer + 1, maxNameBuffer);


}
Person* inputMassPersonFromFile(int* size, char* path)
{
	FILE* input;
	fopen_s(&input, path, "r");
	fscanf_s(input, "%d", size);
	char tmp;
	fscanf_s(input, "%c", &tmp, 1);
	Person* result = (Person*)malloc((*size) * sizeof(Person));
	for (int i = 0; i < *size; ++i)
	{
		inputPersonFromFile(&result[i], input);
	}
	fclose(input);
	return result;
}
void outputPerson(Person* p)
{
	printf("%d, %s\n", p->age, p->name);
}

void outputMassPerson(Person* mass, int size)
{
	for (int i = 0; i < size; ++i)
	{
		outputPerson(&mass[i]);
	}
}

void outputBiggestAgePerson(Person* m, int size)
{
	double biggestage = 0;
	for (int i = 0; i < size; i++)
	{
		if (m[i].age > biggestage)
		{
			biggestage = m[i].age;
		}

	}
	for (int i = 0; i < size; i++)
	{
		if (m[i].age == biggestage)
		{
			printf("Старейшина: %s\n", m[i].name);
		}
	}

}
int main() {
	setlocale(LC_ALL, "Rus");
	int size = 100;
	Person* inputMass = 0;
	inputMass = inputMassPersonFromFile(&size, "person.txt");
	outputMassPerson(inputMass, size);
	outputBiggestAgePerson(inputMass, size);

	system("pause");
	return 0;

}