//@author A0110783L
#pragma once
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>

namespace ComCal_v01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HelpForm
	/// </summary>
	public ref class HelpForm : public System::Windows::Forms::Form
	{
	public:
		HelpForm(void)
		{
			InitializeComponent();
			
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("User commands: add; edit; delete; done; undone; undo; redo; search"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("Time Input: \"HHMM\" E.g.: \"0830\" represents 8:30 AM; \"1600\" represents 4:00 PM"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("Date Input: \"DD/MM/YYYY\" E.g.: \"31/04/2015\" represents 31 April 2015; \"01/05/2015\" represents 1 May 2015"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("Acceptable Day Input: monday, tuesday, wednesday, thursday, friday, saturday, sunday, today, tomorrow, yesterday"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("last <day>, next <day>: last monday, last wednesday, next tuesday, next friday, etc."), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("Add Command Format: The only necessary attribute is <description>, the rest are optional"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("\"add .d <task description> .s <start date/day> <start time> .e <end date/day> <end time> .l <location>\""), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("e.g.: add .d SampleTask .s 14/04/2015 1000 .e 29/06/2016 1100 .l school"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("Token format:"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("- Description: .d, (can be omitted)"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("- Start date and time: .s, from, on"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("- End date and time: .e, to, by"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("- Location: .l, in, at"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("Edit Command Format: Only the token(s) you would like to change need to be specified"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("To edit, simply specify the index of the task, type a token, followed by the content you would like to change it to"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("edit <index> .d <new description> .s <new start date and/or time> .e <new end date and/or time> .l <new location>"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("eg. edit 26 .d Going to school .s 13/04/2015 1600 .e 3/04/2015 1800"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("Token format: .d - <Descripton> , .s - <start date & time> , .e - <end date & time> , .l - <location>"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("Show Command Format:"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("show <date/day> , show <date/day> <todo/done> , show <date/day> <floating/timed/partial/deadline> , show <floating/timed/partial/deadline>"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("show <week> , show <week> <specified date in week> , show <week> <todo/done> , show <week> <date/day> <todo/done>"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("show <month> , show <month> <year> , show <month> <year> <todo/done> , show <next> <week/month> , show <todo/done>"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("Delete/Done/Undon Command Format: Delete/Done/Undone using index seen on the left on the task"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("delete <index> eg. delete 4 , delete <multiple> eg. delete 1 4 2 8 , delete <all>"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("done/undone <index> eg. done/undone 2 , done/undone <multiple> eg. done/undone 2 3 5 1 , done <all> eg. done/undone all"), Environment::NewLine);
			helpBox->Text = String::Concat(helpBox->Text, convertstrToStr("Search <word>"), Environment::NewLine);

			// For adding of new lines:
			//helpBox->Text = String::Concat(helpBox->Text, typeConversions::convertstrToStr(""), Environment::NewLine);
		}

		System::String^ convertstrToStr(std::string userInput) {
			System::String^ strInput;

			strInput = msclr::interop::marshal_as<System::String^>(userInput);

			return strInput;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HelpForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  helpBox;
	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->helpBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// helpBox
			// 
			this->helpBox->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->helpBox->Location = System::Drawing::Point(2, 0);
			this->helpBox->Multiline = true;
			this->helpBox->Name = L"helpBox";
			this->helpBox->ReadOnly = true;
			this->helpBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->helpBox->Size = System::Drawing::Size(1002, 521);
			this->helpBox->TabIndex = 0;
			this->helpBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &HelpForm::exitHelp);
			// 
			// HelpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1003, 520);
			this->Controls->Add(this->helpBox);
			this->Name = L"HelpForm";
			this->Text = L"ComCal Helper";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {}
	private: 

		System::Void exitHelp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if (e->KeyCode == Keys::Escape || e->KeyCode == Keys::End || e->KeyCode == Keys::Enter) {
				this->Close();
			}
		}
	};
}
