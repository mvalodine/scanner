/*
 * main.cpp
 *
 *  Created on: Sep 17, 2014
 *      Author: msteve22
 */
#include "Scanner.h"
#include "Token.h"
#include "Parser.h"

int main(int argc, char *argv[])
{
	string infile = argv[1];
	string outfile = argv[2];
	Scanner scanone (infile, outfile);
	scanone.scan_in();
	Parser parsie(scanone.get_vec(), outfile);
	try
	{
		parsie.Parse();
		parsie.print();
	}
	catch(Token current)
	{
		ofstream outputfile;
		outputfile.open(outfile.c_str());
		outputfile << "Failure!\n";
		outputfile << "  " + current.printToken();
	}
	return 0;
}



