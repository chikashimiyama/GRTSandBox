#include <grt.h>
#include <iostream>

using namespace GRT;
using namespace std;

int main(void){
	cout << "ClassificationData Test" << endl;
	ClassificationData cdata;

	// load data file that in Nick Gillian Format
	if(cdata.loadDatasetFromFile("irisNG.txt")){
	 	cout << "error loading csv file" << endl;
	}

	cdata.printStats();

	cout << "convert dataset to csv" << endl;

	//convert it to CSV. the first column indicate the class
	cdata.saveDatasetToCSVFile("irisCSVFromNG.txt");

	//obviously we can load the data from CSV that we generated
	//note that class names are now lost
	cdata.loadDatasetFromCSVFile("irisCSVFromNG.txt");

	cdata.printStats();

	//try to load a CSV file that includes strings
	//cdata.loadDatasetFromCSVFile("irisCSV.txt", 4);
	//commented out because we get error while loading

	//load CSV file without strings but the classes are stored is the 5th column 
	cdata.loadDatasetFromCSVFile("irisCSVNoText.txt", 4);
	cdata.printStats();

	cdata.loadDatasetFromCSVFile("TestCSV.txt");
	cdata.printStats();

	return 0;
}