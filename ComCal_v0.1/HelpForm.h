#pragma once
#include "Helper.h"
#include "typeConversions.h"

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
			
			std::vector<std::string> helpVec = helper::getHelp();
			for (int i = 0; i < helpVec.size(); i++) {
				if (i % 4 == 0 && i !=0) {
					helpBox->Text = String::Concat(helpBox->Text, Environment::NewLine);
					helpBox->Text = String::Concat(helpBox->Text, typeConversions::convertstrToStr(helpVec[i]), Environment::NewLine);
				}
				else {
					helpBox->Text = String::Concat(helpBox->Text, typeConversions::convertstrToStr(helpVec[i]), Environment::NewLine);
				}
			}
			
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
