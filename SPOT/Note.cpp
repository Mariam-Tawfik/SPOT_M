#include "Note.h"
#include<fstream>
#include <iostream>
#include <string>

#include "GUI/Drawable.h"
#include"GUI/GUI.h"

string Note::getmyNote() {
	fstream inFile("D:\\Notes.txt", ios::in);
	string line;
	int i = 0;
	while (getline(inFile, line)) {
		while (inFile >> myNote) {}
	}
	inFile.close();
	return myNote;
}
void Note::setmyNote(string s) {
	myNote = s+ " \n";
	fstream oFile("D:\\Notes.txt", ios::app);
	oFile << myNote;
}
void Note::DrawMe(GUI* pNote) const {
	Note n;
	pNote->DrawNotes(n);
}