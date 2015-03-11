#include "MonthForm.h"
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>

using namespace ComCal_v01;
using namespace System;
using namespace System::Windows::Forms;

MonthForm::MonthForm(int argc, array<String^>^ argv)
{
	InitializeComponent();

	const char** charFileNames = new const char*[argc];

	if (argc > 0){
		typeConversion(argv, charFileNames, argc);
	}

	_manager = new ComCalManager(argc, charFileNames);

}

void MonthForm::typeConversion(array<System::String^>^ fileNames, const char** strFilesNames, int numOfSpecifiedFiles){

	msclr::interop::marshal_context^ context = gcnew msclr::interop::marshal_context();
	strFilesNames = new const char*[numOfSpecifiedFiles];
	for (int i = 0; i < numOfSpecifiedFiles; i++){
		strFilesNames[i] = context->marshal_as<const char*>(fileNames[i]);

		context = nullptr;
	}

}

System::Void MonthForm::userEnter(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	String^ feedBack;

	if (e->KeyCode == Keys::Enter){
		if (userInputBox->Text == "exit" || userInputBox->Text == "close"){
			Application::Exit();
		}
		else{
			feedBack = _manager->deduceCommand(userInputBox->Text);

			userInputBox->Text = nullptr;
		}
	}
}
