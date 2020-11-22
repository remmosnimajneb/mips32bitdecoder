/********************************
* MIPS 32 Bit Instructions to Readable format
* Extract the format and details of a 32 bit binary MIPS command to Readable format
*
* Author: Benjamin Sommer - BenSommer.net | GitHub @remmosnimajneb
***************************************************************************************/

#include <iostream> 
#include <fstream>
#include <cstring>
#include <string>
using namespace std; 

int main(int argc, char** argv){
	
	string instFormat = "";
	string operation = "";
	string sourceRegs = "";
	string destRegs = "";
	string shift = "";
	string constantOffset = "";
	int jumpVal = 0;


	/*
	* 0. Read in the binary number
	*/
		string binNumber = argv[1];

		/* Add Support for Help */
		if(binNumber == "help"){

			cout<<"Convert MIPS 32 Bit Instruction to readable instructions"<<endl;
			cout<<endl;
			cout<<"Supports instruction formats: "<<endl;
			cout<<endl;
			cout<<"R-Type: [add, addu, sub, subu, and, or, nor, slt, sltu, sll, srl, jr]"<<endl;
			cout<<endl;
			cout<<"I-Type: [beq, bne, addi, addiu, andi, ori, slti, sltiu, lui, lw, sw]"<<endl;
			cout<<endl;
			cout<<"J-Type: [j, jal]"<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"Enter 32 Bit code in command line to get an output of the instruction information"<<endl;

			exit(0);
		}

		cout<<"Input 32 Bit Instruction: "<<binNumber<<endl;
		cout<<endl;

	/*
	* 1. Get Type Format (I, R, J) [First 6 Numbers]
	*/
		int opcVal = stoi(binNumber.substr(0,6), 0, 2);


	/*
	* 2. Now based on that, we can check for all the other values
	*/

		/* J Type */
		if(opcVal == 2 || opcVal == 3){

			instFormat = "J Type";

			string opr = "j";

			if(opcVal == 3){
				opr = "jal";
			}

			jumpVal = stoi(binNumber.substr(6,26), 0, 2);

			cout<<"Operation Format: J-Type"<<endl;
			cout<<"Operation: "<<opr<<endl;
			cout<<"Source Registers: None"<<endl;
			cout<<"Destination Registers: None"<<endl;
			cout<<"Shift Amount: None"<<endl;
			cout<<"Address to Jump: "<<jumpVal<<endl;

		}

		/* R Type */
		if(opcVal == 0){

			instFormat = "R Type";

			int rs = stoi(binNumber.substr(6,5), 0, 2);
			int rt = stoi(binNumber.substr(11,5), 0, 2);
			int rd = stoi(binNumber.substr(16,5), 0, 2);
			int shamt = stoi(binNumber.substr(21,5), 0, 2);
			int funct = stoi(binNumber.substr(26,6), 0, 2);

			/* Compute Funct */
			if(funct == 32){
				operation = "add";
			} else if(funct == 33){
				operation = "addu";
			} else if(funct == 34){
				operation = "sub";
			} else if(funct == 35){
				operation = "subu";
			} else if(funct == 36){
				operation = "and";
			} else if(funct == 37){
				operation = "or";
			} else if(funct == 39){
				operation = "nor";
			} else if(funct == 42){
				operation = "slt";
			} else if(funct == 43){
				operation = "sltu";
			} else if(funct == 0){
				operation = "sll";
			} else if(funct == 2){
				operation = "srl";
			} else if(funct == 32){
				operation = "jr";
			}

			cout<<"Operation Format: R-Type"<<endl;
			cout<<"Operation: "<<operation<<endl;
			cout<<"Source Registers: "<<rs<<" "<<rt<<endl;
			cout<<"Destination Registers: "<<rd<<endl;
			cout<<"Shift Amount: "<<shamt<<endl;
			cout<<"Constant/Offset: None"<<endl;

		}

		/* I Type */
		if(opcVal != 0 && opcVal != 2 && opcVal != 3){

			instFormat = "I Type";

			int op = stoi(binNumber.substr(0,6), 0, 2);
			int rs = stoi(binNumber.substr(6,5), 0, 2);
			int rt = stoi(binNumber.substr(11,5), 0, 2);
			int immed = stoi(binNumber.substr(16,16), 0, 2);

			/* Compute Funct */
			if(op == 4){
				operation = "beq";
			} else if(op == 5){
				operation = "bne";
			} else if(op == 8){
				operation = "addi";
			} else if(op == 9){
				operation = "addiu";
			} else if(op == 12){
				operation = "andi";
			} else if(op == 13){
				operation = "ori";
			} else if(op == 10){
				operation = "slti";
			} else if(op == 11){
				operation = "sltiu";
			} else if(op == 15){
				operation = "lui";
			} else if(op == 35){
				operation = "lw";
			} else if(op == 43){
				operation = "sw";
			}

			cout<<"Operation Format: I-Type"<<endl;
			cout<<"Operation: "<<operation<<endl;
			cout<<"Source Registers: "<<rs<<endl;
			cout<<"Destination Registers: "<<rt<<endl;
			cout<<"Shift Amount: None"<<endl;
			cout<<"Constant/Offset: "<<immed<<endl;

		}

}