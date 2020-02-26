#include "networks.h"

TravelNetwork::TravelNetwork() {
	size = 10;
	fileList = new MyList;
	darr = new Airport[size+1];

	for(int i = 1; i < size; i++)
		darr[i].setNum(i);
}
    
TravelNetwork::~TravelNetwork() {
	delete [] darr;
	delete fileList;
}

void TravelNetwork::processCommandLoop (FILE* inFile)
{
	char  buffer[300];
	char* input;

	input = fgets ( buffer, 300, inFile );

	while (input != NULL)
	{
		char* command;
		command = strtok (input , " \n\t");

		printf ("*%s*\n", command);

		if ( command == NULL )
			printf ("Blank Line\n");

		else if ( strcmp (command, "q") == 0){
			this->~TravelNetwork();
			exit(1);
		}

		else if ( strcmp (command, "?") == 0)
			showCommands();

		else if ( strcmp (command, "t") == 0)
			doTravel();

		else if ( strcmp (command, "r") == 0)
			doResize();

		else if ( strcmp (command, "i") == 0)
			doInsert();

		else if ( strcmp (command, "d") == 0)
			doDelete();

		else if ( strcmp (command, "l") == 0)
			doList();

		else if ( strcmp (command, "f") == 0)
			doFile();

		else if ( strcmp (command, "#") == 0)
			;

		else
			printf ("Command is not known: %s\n", command);

		input = fgets ( buffer, 300, inFile );

	}
}

void TravelNetwork::showCommands()
{
	printf ("The commands for this project are:\n");
	printf ("  q \n");
	printf ("  ? \n");
	printf ("  # \n");
	printf ("  t <int1> <int2> \n");
	printf ("  r <int> \n");
	printf ("  i <int1> <int2> \n");
	printf ("  d <int1> <int2> \n");
	printf ("  l \n");
	printf ("  f <filename> \n");
}

void TravelNetwork::doTravel()
{
	int val1 = 0;
	int val2 = 0;

	char* next = strtok (NULL, " \n\t");
	if ( next == NULL )
	{
		printf ("Integer value expected\n");
		return;
	}
	val1 = atoi ( next );
	if ( val1 == 0 && strcmp (next, "0") != 0)
	{
		printf ("Integer value expected\n");
		return;
	}

	// get another integer value from the input
	next = strtok (NULL, " \n\t");
	if ( next == NULL )
	{
		printf ("Integer value expected\n");
		return;
	}
	val2 = atoi ( next );
	if ( val2 == 0 && strcmp (next, "0") != 0)
	{
		printf ("Integer value expected\n");
		return;
	}

	
	if(val1 < 1 || val1 > size || val2 < 1 || val2 > size) {
		 std::cout << "Error: Number not valid or outside range!" << std::endl;
		 return;
	}

	printf ("Performing the Travel Command from %d to %d\n",
			val1, val2);

	depthFirstSearchHelper(val1, val2);


}

void TravelNetwork::doResize()
{
	int val1;

	char* next = strtok (NULL, "\n\t");
	if (next == NULL){
		std::cout << "Integer value expected" << std::endl;
		return;
	}

	val1 = atoi(next);

	if(val1 == 0 && strcmp(next, "0") != 0){
		std::cout << "Integer value expected" << std::endl;
		return;
	}

	if(val1 >= 1) {
		std::cout << "Performing the Resize Command with " << val1 << std::endl;
		delete [] darr;
		size = val1;
		darr = new Airport[size+1];

		for(int i = 0; i < size+1; i++)
			darr[i].setNum(i);
	}
	
	std::cout << "Error: Network size should be at least 1!\n";
}

void TravelNetwork::doInsert()
{
	int val1 = 0 , val2 = 0;
	
	char* next = strtok (NULL, " \n\t");
		if ( next == NULL )
		{
			printf ("Integer value expected\n");
			return;
		}
		val1 = atoi ( next );
		if (val1 == 0 && strcmp (next, "0") != 0)
		{
			printf ("Integer value expected\n");
			return;
		}

		
		next = strtok (NULL, " \n\t");
		if ( next == NULL )
		{
			printf ("Integer value expected\n");
			return;
		}
		val2 = atoi ( next );
		if ( val2 == 0 && strcmp (next, "0") != 0)
		{
			printf ("Integer value expected\n");
			return;
		}
		
		 if(val1 < 1 || val1 > size || val2 < 1 || val2 > size) {
			 std::cout << "Error: Number not valid or outside range!" << std::endl;
			 return;
		}

		std::cout << "Performing the insert command from " << val1 << " to " << val2 << std::endl;
		darr[val1].ins(val2);
}

void TravelNetwork::doDelete()
{
	int val1 = 0 , val2 = 0;
	
	char* next = strtok (NULL, " \n\t");
		if ( next == NULL )
		{
			printf ("Integer value expected\n");
			return;
		}
		val1 = atoi ( next );
		if ( val1 == 0 && strcmp (next, "0") != 0)
		{
			printf ("Integer value expected\n");
			return;
		}

		next = strtok (NULL, " \n\t");
		if ( next == NULL )
		{
			printf ("Integer value expected\n");
			return;
		}
		val2 = atoi ( next );
		if ( val2 == 0 && strcmp (next, "0") != 0)
		{
			printf ("Integer value expected\n");
			return;
		}

		std::cout << "Performing the delete command from " << val1 << " to " << val2 << std::endl;
		darr[val1].del(val2);
}

void TravelNetwork::doList()
{
	std::cout << "Aiport Connections:\n";
	
	for(int i = 1; i < size+1; i++) {
		std::cout << i << "->";
		darr[i].show();
	}
	
	std::cout << std::endl;
}

void TravelNetwork::doFile() { //incomplete
	/*
	char* fname = strtok (NULL, " \n\t");
	if ( fname == NULL )
	{
		printf ("Filename expected\n");
		return;
	}

	if(fileList->contains()){       	
		std::cout << "Error: " << fname << " is already in use.\n";
		return;
	}
	
	FILE* f = fopen(fname, "r");
	
	if(f == NULL) {
		std::cout << "Error: Cannot open file!\n";
		return;
	}


	printf ("Performing the File command with file: %s\n", fname);

	// next steps:  (if any step fails: print an error message and return )
	//  1. verify the file name is not currently in use
	//  2. open the file using fopen creating a new instance of FILE*
	//  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
	//  4. close the file when processCommandLoop() returns
	
	fileList->push(fname);
	processCommandLoop(f);
	fclose(f);
	fileList->pop(fname);
	*/
	return;
}

void TravelNetwork::depthFirstSearchHelper(int x, int y) {
	for(int i = 1; i < size+1; i++)
		darr[i].setNotVisited();
	
	if (dfs(x, y) == true)
		std::cout << "You can get from airport " << x << " to airport " << y << " in one or more flights\n";
	else
		std::cout << "You CANNOT get from airport " << x << " to airport " << y << " in one or more flights\n";
}

bool TravelNetwork::dfs(int a, int b) {
	MyList* tempList = darr[a].getList();

	for(int i = 0; i < tempList->getLength(); i++)
	{
		int id = tempList->getNthNode(i);
		if(id == b)
			return true;
		
		if(!(darr[id].isVisited()))
		{
			darr[id].setVisted();
			if(dfs(id, b))
				return true;
		}
	}
	return false;
}

int main (int argc, char** argv)
{
    // set up the variable inFile to read from standard input
    FILE* inFile = stdin;

    // set up the data needed for the airport adjcency list
    TravelNetwork airportData;

    // call the method that reads and parses the input
    airportData.showCommands();
    printf ("\nEnter commands at blank line\n");
    printf ("    (No prompts are given because of f command)\n");
    airportData.processCommandLoop (inFile);

    printf ("Goodbye\n");
    return 1;
}