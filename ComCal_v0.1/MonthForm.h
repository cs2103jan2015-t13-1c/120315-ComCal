#pragma once

#include <string>
#include "ComCalManager.h"
#include "TextStorage.h"

namespace ComCal_v01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MonthForm
	/// </summary>
	public ref class MonthForm : public System::Windows::Forms::Form
	{
	public:
		MonthForm(int, array<String^>^);
		void setCalendarDate_MonthForm(struct tm*);

	private:
		ComCalManager* _manager;

		System::Collections::Generic::List<System::Windows::Forms::TextBox^> dateList;
		System::Collections::Generic::List<System::Windows::Forms::TextBox^> taskList;

		bool _ctrlHeld;

	private: 
		void storeDateTextBlockInList();
		void storeTasksTextBlockInList();
		
		System::String^ incrementStringDate(System::String^, int);
		System::String^ setMonthPageTitle(struct tm*);

	private: System::Windows::Forms::Button^  resetButton;
	private: System::Windows::Forms::TextBox^  dateBox11;

	private: System::Windows::Forms::TextBox^  taskBox11;

	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  showBox;



	private: System::Windows::Forms::TableLayoutPanel^  table57;

	private: System::Windows::Forms::TextBox^  taskBox57;

	private: System::Windows::Forms::TextBox^  dateBox57;

	private: System::Windows::Forms::TableLayoutPanel^  table56;

	private: System::Windows::Forms::TextBox^  taskBox56;

	private: System::Windows::Forms::TextBox^  dateBox56;

	private: System::Windows::Forms::TableLayoutPanel^  table55;

	private: System::Windows::Forms::TextBox^  taskBox55;

	private: System::Windows::Forms::TextBox^  dateBox55;

	private: System::Windows::Forms::TableLayoutPanel^  table54;

	private: System::Windows::Forms::TextBox^  taskBox54;

	private: System::Windows::Forms::TextBox^  dateBox54;

	private: System::Windows::Forms::TableLayoutPanel^  table53;

	private: System::Windows::Forms::TextBox^  taskBox53;

	private: System::Windows::Forms::TextBox^  dateBox53;

	private: System::Windows::Forms::TableLayoutPanel^  table52;

	private: System::Windows::Forms::TextBox^  taskBox52;

	private: System::Windows::Forms::TextBox^  dateBox52;

	private: System::Windows::Forms::TableLayoutPanel^  table47;

	private: System::Windows::Forms::TextBox^  taskBox47;

	private: System::Windows::Forms::TextBox^  dateBox47;

	private: System::Windows::Forms::TableLayoutPanel^  table46;

	private: System::Windows::Forms::TextBox^  taskBox46;

	private: System::Windows::Forms::TextBox^  dateBox46;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel26;

	private: System::Windows::Forms::TextBox^  taskBox45;

	private: System::Windows::Forms::TextBox^  dateBox45;

	private: System::Windows::Forms::TableLayoutPanel^  table44;

	private: System::Windows::Forms::TextBox^  taskBox44;

	private: System::Windows::Forms::TextBox^  dateBox44;


	private: System::Windows::Forms::TableLayoutPanel^  table43;

	private: System::Windows::Forms::TextBox^  taskBox43;

	private: System::Windows::Forms::TextBox^  dateBox43;

	private: System::Windows::Forms::TableLayoutPanel^  table42;

	private: System::Windows::Forms::TextBox^  taskBox42;

	private: System::Windows::Forms::TextBox^  dateBox42;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel22;
	private: System::Windows::Forms::TextBox^  taskBox41;


	private: System::Windows::Forms::TextBox^  dateBox41;

	private: System::Windows::Forms::TableLayoutPanel^  table37;

	private: System::Windows::Forms::TextBox^  taskBox37;

	private: System::Windows::Forms::TextBox^  dateBox37;

	private: System::Windows::Forms::TableLayoutPanel^  table36;

	private: System::Windows::Forms::TextBox^  taskBox36;

	private: System::Windows::Forms::TextBox^  dateBox36;

	private: System::Windows::Forms::TableLayoutPanel^  table35;

	private: System::Windows::Forms::TextBox^  taskBox35;

	private: System::Windows::Forms::TextBox^  dateBox35;

	private: System::Windows::Forms::TableLayoutPanel^  table34;

	private: System::Windows::Forms::TextBox^  taskBox34;

	private: System::Windows::Forms::TextBox^  dateBox34;

	private: System::Windows::Forms::TableLayoutPanel^  table33;

	private: System::Windows::Forms::TextBox^  taskBox33;

	private: System::Windows::Forms::TextBox^  dateBox33;

	private: System::Windows::Forms::TableLayoutPanel^  table32;

	private: System::Windows::Forms::TextBox^  taskBox32;

	private: System::Windows::Forms::TextBox^  dateBox32;

	private: System::Windows::Forms::TableLayoutPanel^  table31;

	private: System::Windows::Forms::TextBox^  taskBox31;

	private: System::Windows::Forms::TextBox^  dateBox31;

	private: System::Windows::Forms::TableLayoutPanel^  table27;

	private: System::Windows::Forms::TextBox^  taskBox27;

	private: System::Windows::Forms::TextBox^  dateBox27;

	private: System::Windows::Forms::TableLayoutPanel^  table26;

	private: System::Windows::Forms::TextBox^  taskBox26;

	private: System::Windows::Forms::TextBox^  dateBox26;

	private: System::Windows::Forms::TableLayoutPanel^  table25;


	private: System::Windows::Forms::TextBox^  taskBox25;

	private: System::Windows::Forms::TextBox^  dateBox25;

	private: System::Windows::Forms::TableLayoutPanel^  table24;

	private: System::Windows::Forms::TextBox^  taskBox24;

	private: System::Windows::Forms::TextBox^  dateBox24;

	private: System::Windows::Forms::TableLayoutPanel^  table23;

	private: System::Windows::Forms::TextBox^  taskBox23;

	private: System::Windows::Forms::TextBox^  dateBox23;

	private: System::Windows::Forms::TableLayoutPanel^  table22;

	private: System::Windows::Forms::TextBox^  taskBox22;

	private: System::Windows::Forms::TextBox^  dateBox22;

	private: System::Windows::Forms::TableLayoutPanel^  table21;

	private: System::Windows::Forms::TextBox^  taskBox21;

	private: System::Windows::Forms::TextBox^  dateBox21;


	private: System::Windows::Forms::TableLayoutPanel^  table17;

	private: System::Windows::Forms::TextBox^  taskBox17;

	private: System::Windows::Forms::TextBox^  dateBox17;

	private: System::Windows::Forms::TableLayoutPanel^  table16;

	private: System::Windows::Forms::TextBox^  taskBox16;

	private: System::Windows::Forms::TextBox^  dateBox16;

	private: System::Windows::Forms::TableLayoutPanel^  table15;

	private: System::Windows::Forms::TextBox^  taskBox15;

	private: System::Windows::Forms::TextBox^  dateBox15;

private: System::Windows::Forms::TableLayoutPanel^  table14;

private: System::Windows::Forms::TextBox^  taskBox14;

private: System::Windows::Forms::TextBox^  dateBox14;

private: System::Windows::Forms::TableLayoutPanel^  table13;

private: System::Windows::Forms::TextBox^  taskBox13;

private: System::Windows::Forms::TextBox^  dateBox13;

private: System::Windows::Forms::TableLayoutPanel^  table12;
private: System::Windows::Forms::TextBox^  taskBox12;
private: System::Windows::Forms::TextBox^  dateBox12;
private: System::Windows::Forms::TableLayoutPanel^  table51;
private: System::Windows::Forms::TextBox^  taskBox51;
private: System::Windows::Forms::TextBox^  dateBox51;
private: System::Windows::Forms::TextBox^  textBox1;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MonthForm()
		{
			if (components)
			{
				delete components;
			}

			delete _manager;
		}
		//Function to set the calendar----------------------------------------------------------------


		//--------------------------------------------------------------------------------------------

	private: System::Windows::Forms::TableLayoutPanel^  monthPanel;

	private: System::Windows::Forms::TextBox^  dayTxtBlkSun;
	private: System::Windows::Forms::TextBox^  dayTxtBlkSat;
	private: System::Windows::Forms::TextBox^  dayTxtBlkFri;
	private: System::Windows::Forms::TextBox^  dayTxtBlkThur;
	private: System::Windows::Forms::TextBox^  dayTxtBlkWed;
	private: System::Windows::Forms::TextBox^  dayTxtBlkTue;
	private: System::Windows::Forms::TextBox^  dayTxtBlkMon;


	private: System::Windows::Forms::TextBox^  userInputBox;
private: System::Windows::Forms::TableLayoutPanel^  table11;
private: System::Windows::Forms::TextBox^  monthFormTitle;



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
			this->monthPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table51 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox51 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox51 = (gcnew System::Windows::Forms::TextBox());
			this->table57 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox57 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox57 = (gcnew System::Windows::Forms::TextBox());
			this->table56 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox56 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox56 = (gcnew System::Windows::Forms::TextBox());
			this->table55 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox55 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox55 = (gcnew System::Windows::Forms::TextBox());
			this->table54 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox54 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox54 = (gcnew System::Windows::Forms::TextBox());
			this->table53 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox53 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox53 = (gcnew System::Windows::Forms::TextBox());
			this->table52 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox52 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox52 = (gcnew System::Windows::Forms::TextBox());
			this->table47 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox47 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox47 = (gcnew System::Windows::Forms::TextBox());
			this->table46 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox46 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox46 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel26 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox45 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox45 = (gcnew System::Windows::Forms::TextBox());
			this->table44 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox44 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox44 = (gcnew System::Windows::Forms::TextBox());
			this->table43 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox43 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox43 = (gcnew System::Windows::Forms::TextBox());
			this->table42 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox42 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox42 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel22 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox41 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox41 = (gcnew System::Windows::Forms::TextBox());
			this->table37 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox37 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox37 = (gcnew System::Windows::Forms::TextBox());
			this->table36 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox36 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox36 = (gcnew System::Windows::Forms::TextBox());
			this->table35 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox35 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox35 = (gcnew System::Windows::Forms::TextBox());
			this->table34 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox34 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox34 = (gcnew System::Windows::Forms::TextBox());
			this->table33 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox33 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox33 = (gcnew System::Windows::Forms::TextBox());
			this->table32 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox32 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox32 = (gcnew System::Windows::Forms::TextBox());
			this->table31 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox31 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox31 = (gcnew System::Windows::Forms::TextBox());
			this->table27 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox27 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox27 = (gcnew System::Windows::Forms::TextBox());
			this->table26 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox26 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox26 = (gcnew System::Windows::Forms::TextBox());
			this->table25 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox25 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox25 = (gcnew System::Windows::Forms::TextBox());
			this->table24 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox24 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox24 = (gcnew System::Windows::Forms::TextBox());
			this->table23 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox23 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox23 = (gcnew System::Windows::Forms::TextBox());
			this->table22 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox22 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox22 = (gcnew System::Windows::Forms::TextBox());
			this->table21 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox21 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox21 = (gcnew System::Windows::Forms::TextBox());
			this->table17 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox17 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox17 = (gcnew System::Windows::Forms::TextBox());
			this->table16 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox16 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox16 = (gcnew System::Windows::Forms::TextBox());
			this->table15 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox15 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox15 = (gcnew System::Windows::Forms::TextBox());
			this->table14 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox14 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox14 = (gcnew System::Windows::Forms::TextBox());
			this->table13 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox13 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox13 = (gcnew System::Windows::Forms::TextBox());
			this->table12 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox12 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox12 = (gcnew System::Windows::Forms::TextBox());
			this->dayTxtBlkSat = (gcnew System::Windows::Forms::TextBox());
			this->dayTxtBlkFri = (gcnew System::Windows::Forms::TextBox());
			this->dayTxtBlkThur = (gcnew System::Windows::Forms::TextBox());
			this->dayTxtBlkTue = (gcnew System::Windows::Forms::TextBox());
			this->dayTxtBlkSun = (gcnew System::Windows::Forms::TextBox());
			this->dayTxtBlkMon = (gcnew System::Windows::Forms::TextBox());
			this->table11 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->taskBox11 = (gcnew System::Windows::Forms::TextBox());
			this->dateBox11 = (gcnew System::Windows::Forms::TextBox());
			this->dayTxtBlkWed = (gcnew System::Windows::Forms::TextBox());
			this->userInputBox = (gcnew System::Windows::Forms::TextBox());
			this->monthFormTitle = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->showBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->monthPanel->SuspendLayout();
			this->table51->SuspendLayout();
			this->table57->SuspendLayout();
			this->table56->SuspendLayout();
			this->table55->SuspendLayout();
			this->table54->SuspendLayout();
			this->table53->SuspendLayout();
			this->table52->SuspendLayout();
			this->table47->SuspendLayout();
			this->table46->SuspendLayout();
			this->tableLayoutPanel26->SuspendLayout();
			this->table44->SuspendLayout();
			this->table43->SuspendLayout();
			this->table42->SuspendLayout();
			this->tableLayoutPanel22->SuspendLayout();
			this->table37->SuspendLayout();
			this->table36->SuspendLayout();
			this->table35->SuspendLayout();
			this->table34->SuspendLayout();
			this->table33->SuspendLayout();
			this->table32->SuspendLayout();
			this->table31->SuspendLayout();
			this->table27->SuspendLayout();
			this->table26->SuspendLayout();
			this->table25->SuspendLayout();
			this->table24->SuspendLayout();
			this->table23->SuspendLayout();
			this->table22->SuspendLayout();
			this->table21->SuspendLayout();
			this->table17->SuspendLayout();
			this->table16->SuspendLayout();
			this->table15->SuspendLayout();
			this->table14->SuspendLayout();
			this->table13->SuspendLayout();
			this->table12->SuspendLayout();
			this->table11->SuspendLayout();
			this->SuspendLayout();
			// 
			// monthPanel
			// 
			this->monthPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->monthPanel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->monthPanel->ColumnCount = 7;
			this->monthPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->monthPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 14.28572F)));
			this->monthPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 14.28572F)));
			this->monthPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 14.28572F)));
			this->monthPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 14.28572F)));
			this->monthPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 14.28572F)));
			this->monthPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 14.28572F)));
			this->monthPanel->Controls->Add(this->table51, 0, 5);
			this->monthPanel->Controls->Add(this->table57, 6, 5);
			this->monthPanel->Controls->Add(this->table56, 5, 5);
			this->monthPanel->Controls->Add(this->table55, 4, 5);
			this->monthPanel->Controls->Add(this->table54, 3, 5);
			this->monthPanel->Controls->Add(this->table53, 2, 5);
			this->monthPanel->Controls->Add(this->table52, 1, 5);
			this->monthPanel->Controls->Add(this->table47, 6, 4);
			this->monthPanel->Controls->Add(this->table46, 5, 4);
			this->monthPanel->Controls->Add(this->tableLayoutPanel26, 4, 4);
			this->monthPanel->Controls->Add(this->table44, 3, 4);
			this->monthPanel->Controls->Add(this->table43, 2, 4);
			this->monthPanel->Controls->Add(this->table42, 1, 4);
			this->monthPanel->Controls->Add(this->tableLayoutPanel22, 0, 4);
			this->monthPanel->Controls->Add(this->table37, 6, 3);
			this->monthPanel->Controls->Add(this->table36, 5, 3);
			this->monthPanel->Controls->Add(this->table35, 4, 3);
			this->monthPanel->Controls->Add(this->table34, 3, 3);
			this->monthPanel->Controls->Add(this->table33, 2, 3);
			this->monthPanel->Controls->Add(this->table32, 1, 3);
			this->monthPanel->Controls->Add(this->table31, 0, 3);
			this->monthPanel->Controls->Add(this->table27, 6, 2);
			this->monthPanel->Controls->Add(this->table26, 5, 2);
			this->monthPanel->Controls->Add(this->table25, 4, 2);
			this->monthPanel->Controls->Add(this->table24, 3, 2);
			this->monthPanel->Controls->Add(this->table23, 2, 2);
			this->monthPanel->Controls->Add(this->table22, 1, 2);
			this->monthPanel->Controls->Add(this->table21, 0, 2);
			this->monthPanel->Controls->Add(this->table17, 6, 1);
			this->monthPanel->Controls->Add(this->table16, 5, 1);
			this->monthPanel->Controls->Add(this->table15, 4, 1);
			this->monthPanel->Controls->Add(this->table14, 3, 1);
			this->monthPanel->Controls->Add(this->table13, 2, 1);
			this->monthPanel->Controls->Add(this->table12, 1, 1);
			this->monthPanel->Controls->Add(this->dayTxtBlkSat, 6, 0);
			this->monthPanel->Controls->Add(this->dayTxtBlkFri, 5, 0);
			this->monthPanel->Controls->Add(this->dayTxtBlkThur, 4, 0);
			this->monthPanel->Controls->Add(this->dayTxtBlkTue, 2, 0);
			this->monthPanel->Controls->Add(this->dayTxtBlkSun, 0, 0);
			this->monthPanel->Controls->Add(this->dayTxtBlkMon, 1, 0);
			this->monthPanel->Controls->Add(this->table11, 0, 1);
			this->monthPanel->Controls->Add(this->dayTxtBlkWed, 3, 0);
			this->monthPanel->Enabled = false;
			this->monthPanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->monthPanel->Location = System::Drawing::Point(304, 37);
			this->monthPanel->Name = L"monthPanel";
			this->monthPanel->RowCount = 6;
			this->monthPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.538284F)));
			this->monthPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.09234F)));
			this->monthPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.09234F)));
			this->monthPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.09234F)));
			this->monthPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.09234F)));
			this->monthPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.09234F)));
			this->monthPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->monthPanel->Size = System::Drawing::Size(750, 454);
			this->monthPanel->TabIndex = 0;
			this->monthPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MonthForm::monthPanel_Paint);
			// 
			// table51
			// 
			this->table51->ColumnCount = 1;
			this->table51->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table51->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table51->Controls->Add(this->taskBox51, 0, 1);
			this->table51->Controls->Add(this->dateBox51, 0, 0);
			this->table51->Location = System::Drawing::Point(4, 371);
			this->table51->Name = L"table51";
			this->table51->RowCount = 2;
			this->table51->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table51->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table51->Size = System::Drawing::Size(99, 73);
			this->table51->TabIndex = 42;
			// 
			// taskBox51
			// 
			this->taskBox51->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox51->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox51->Location = System::Drawing::Point(3, 22);
			this->taskBox51->Multiline = true;
			this->taskBox51->Name = L"taskBox51";
			this->taskBox51->Size = System::Drawing::Size(93, 48);
			this->taskBox51->TabIndex = 1;
			// 
			// dateBox51
			// 
			this->dateBox51->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox51->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox51->Location = System::Drawing::Point(3, 3);
			this->dateBox51->Name = L"dateBox51";
			this->dateBox51->Size = System::Drawing::Size(93, 14);
			this->dateBox51->TabIndex = 0;
			// 
			// table57
			// 
			this->table57->ColumnCount = 1;
			this->table57->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table57->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table57->Controls->Add(this->taskBox57, 0, 1);
			this->table57->Controls->Add(this->dateBox57, 0, 0);
			this->table57->Location = System::Drawing::Point(645, 371);
			this->table57->Name = L"table57";
			this->table57->RowCount = 2;
			this->table57->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table57->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table57->Size = System::Drawing::Size(99, 73);
			this->table57->TabIndex = 41;
			// 
			// taskBox57
			// 
			this->taskBox57->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox57->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox57->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox57->Location = System::Drawing::Point(3, 22);
			this->taskBox57->Multiline = true;
			this->taskBox57->Name = L"taskBox57";
			this->taskBox57->Size = System::Drawing::Size(93, 48);
			this->taskBox57->TabIndex = 1;
			// 
			// dateBox57
			// 
			this->dateBox57->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox57->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox57->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox57->Location = System::Drawing::Point(3, 3);
			this->dateBox57->Name = L"dateBox57";
			this->dateBox57->Size = System::Drawing::Size(93, 14);
			this->dateBox57->TabIndex = 0;
			// 
			// table56
			// 
			this->table56->ColumnCount = 1;
			this->table56->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table56->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table56->Controls->Add(this->taskBox56, 0, 1);
			this->table56->Controls->Add(this->dateBox56, 0, 0);
			this->table56->Location = System::Drawing::Point(538, 371);
			this->table56->Name = L"table56";
			this->table56->RowCount = 2;
			this->table56->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table56->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table56->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->table56->Size = System::Drawing::Size(99, 73);
			this->table56->TabIndex = 40;
			// 
			// taskBox56
			// 
			this->taskBox56->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox56->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox56->Location = System::Drawing::Point(3, 22);
			this->taskBox56->Multiline = true;
			this->taskBox56->Name = L"taskBox56";
			this->taskBox56->Size = System::Drawing::Size(93, 48);
			this->taskBox56->TabIndex = 1;
			// 
			// dateBox56
			// 
			this->dateBox56->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox56->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox56->Location = System::Drawing::Point(3, 3);
			this->dateBox56->Name = L"dateBox56";
			this->dateBox56->Size = System::Drawing::Size(93, 14);
			this->dateBox56->TabIndex = 0;
			// 
			// table55
			// 
			this->table55->ColumnCount = 1;
			this->table55->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table55->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table55->Controls->Add(this->taskBox55, 0, 1);
			this->table55->Controls->Add(this->dateBox55, 0, 0);
			this->table55->Location = System::Drawing::Point(431, 371);
			this->table55->Name = L"table55";
			this->table55->RowCount = 2;
			this->table55->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table55->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table55->Size = System::Drawing::Size(99, 73);
			this->table55->TabIndex = 39;
			// 
			// taskBox55
			// 
			this->taskBox55->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox55->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox55->Location = System::Drawing::Point(3, 22);
			this->taskBox55->Multiline = true;
			this->taskBox55->Name = L"taskBox55";
			this->taskBox55->Size = System::Drawing::Size(93, 48);
			this->taskBox55->TabIndex = 1;
			// 
			// dateBox55
			// 
			this->dateBox55->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox55->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox55->Location = System::Drawing::Point(3, 3);
			this->dateBox55->Name = L"dateBox55";
			this->dateBox55->Size = System::Drawing::Size(93, 14);
			this->dateBox55->TabIndex = 0;
			// 
			// table54
			// 
			this->table54->ColumnCount = 1;
			this->table54->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table54->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table54->Controls->Add(this->taskBox54, 0, 1);
			this->table54->Controls->Add(this->dateBox54, 0, 0);
			this->table54->Location = System::Drawing::Point(324, 371);
			this->table54->Name = L"table54";
			this->table54->RowCount = 2;
			this->table54->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table54->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table54->Size = System::Drawing::Size(99, 73);
			this->table54->TabIndex = 38;
			// 
			// taskBox54
			// 
			this->taskBox54->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox54->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox54->Location = System::Drawing::Point(3, 22);
			this->taskBox54->Multiline = true;
			this->taskBox54->Name = L"taskBox54";
			this->taskBox54->Size = System::Drawing::Size(93, 48);
			this->taskBox54->TabIndex = 1;
			// 
			// dateBox54
			// 
			this->dateBox54->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox54->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox54->Location = System::Drawing::Point(3, 3);
			this->dateBox54->Name = L"dateBox54";
			this->dateBox54->Size = System::Drawing::Size(93, 14);
			this->dateBox54->TabIndex = 0;
			// 
			// table53
			// 
			this->table53->ColumnCount = 1;
			this->table53->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table53->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table53->Controls->Add(this->taskBox53, 0, 1);
			this->table53->Controls->Add(this->dateBox53, 0, 0);
			this->table53->Location = System::Drawing::Point(217, 371);
			this->table53->Name = L"table53";
			this->table53->RowCount = 2;
			this->table53->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table53->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table53->Size = System::Drawing::Size(99, 73);
			this->table53->TabIndex = 37;
			// 
			// taskBox53
			// 
			this->taskBox53->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox53->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox53->Location = System::Drawing::Point(3, 22);
			this->taskBox53->Multiline = true;
			this->taskBox53->Name = L"taskBox53";
			this->taskBox53->Size = System::Drawing::Size(93, 48);
			this->taskBox53->TabIndex = 1;
			// 
			// dateBox53
			// 
			this->dateBox53->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox53->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox53->Location = System::Drawing::Point(3, 3);
			this->dateBox53->Name = L"dateBox53";
			this->dateBox53->Size = System::Drawing::Size(93, 14);
			this->dateBox53->TabIndex = 0;
			// 
			// table52
			// 
			this->table52->ColumnCount = 1;
			this->table52->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table52->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table52->Controls->Add(this->taskBox52, 0, 1);
			this->table52->Controls->Add(this->dateBox52, 0, 0);
			this->table52->Location = System::Drawing::Point(110, 371);
			this->table52->Name = L"table52";
			this->table52->RowCount = 2;
			this->table52->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table52->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table52->Size = System::Drawing::Size(99, 73);
			this->table52->TabIndex = 36;
			// 
			// taskBox52
			// 
			this->taskBox52->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox52->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox52->Location = System::Drawing::Point(3, 22);
			this->taskBox52->Multiline = true;
			this->taskBox52->Name = L"taskBox52";
			this->taskBox52->Size = System::Drawing::Size(93, 48);
			this->taskBox52->TabIndex = 1;
			// 
			// dateBox52
			// 
			this->dateBox52->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox52->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox52->Location = System::Drawing::Point(3, 3);
			this->dateBox52->Name = L"dateBox52";
			this->dateBox52->Size = System::Drawing::Size(93, 14);
			this->dateBox52->TabIndex = 0;
			// 
			// table47
			// 
			this->table47->ColumnCount = 1;
			this->table47->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table47->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table47->Controls->Add(this->taskBox47, 0, 1);
			this->table47->Controls->Add(this->dateBox47, 0, 0);
			this->table47->Location = System::Drawing::Point(645, 290);
			this->table47->Name = L"table47";
			this->table47->RowCount = 2;
			this->table47->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table47->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table47->Size = System::Drawing::Size(99, 73);
			this->table47->TabIndex = 35;
			// 
			// taskBox47
			// 
			this->taskBox47->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox47->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox47->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox47->Location = System::Drawing::Point(3, 22);
			this->taskBox47->Multiline = true;
			this->taskBox47->Name = L"taskBox47";
			this->taskBox47->Size = System::Drawing::Size(93, 48);
			this->taskBox47->TabIndex = 1;
			// 
			// dateBox47
			// 
			this->dateBox47->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox47->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox47->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox47->Location = System::Drawing::Point(3, 3);
			this->dateBox47->Name = L"dateBox47";
			this->dateBox47->Size = System::Drawing::Size(93, 14);
			this->dateBox47->TabIndex = 0;
			// 
			// table46
			// 
			this->table46->ColumnCount = 1;
			this->table46->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table46->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table46->Controls->Add(this->taskBox46, 0, 1);
			this->table46->Controls->Add(this->dateBox46, 0, 0);
			this->table46->Location = System::Drawing::Point(538, 290);
			this->table46->Name = L"table46";
			this->table46->RowCount = 2;
			this->table46->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table46->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table46->Size = System::Drawing::Size(99, 73);
			this->table46->TabIndex = 34;
			// 
			// taskBox46
			// 
			this->taskBox46->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox46->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox46->Location = System::Drawing::Point(3, 22);
			this->taskBox46->Multiline = true;
			this->taskBox46->Name = L"taskBox46";
			this->taskBox46->Size = System::Drawing::Size(93, 48);
			this->taskBox46->TabIndex = 1;
			// 
			// dateBox46
			// 
			this->dateBox46->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox46->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox46->Location = System::Drawing::Point(3, 3);
			this->dateBox46->Name = L"dateBox46";
			this->dateBox46->Size = System::Drawing::Size(93, 14);
			this->dateBox46->TabIndex = 0;
			// 
			// tableLayoutPanel26
			// 
			this->tableLayoutPanel26->ColumnCount = 1;
			this->tableLayoutPanel26->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35.52632F)));
			this->tableLayoutPanel26->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				64.47369F)));
			this->tableLayoutPanel26->Controls->Add(this->taskBox45, 0, 1);
			this->tableLayoutPanel26->Controls->Add(this->dateBox45, 0, 0);
			this->tableLayoutPanel26->Location = System::Drawing::Point(431, 290);
			this->tableLayoutPanel26->Name = L"tableLayoutPanel26";
			this->tableLayoutPanel26->RowCount = 2;
			this->tableLayoutPanel26->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->tableLayoutPanel26->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->tableLayoutPanel26->Size = System::Drawing::Size(99, 73);
			this->tableLayoutPanel26->TabIndex = 33;
			// 
			// taskBox45
			// 
			this->taskBox45->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox45->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox45->Location = System::Drawing::Point(3, 22);
			this->taskBox45->Multiline = true;
			this->taskBox45->Name = L"taskBox45";
			this->taskBox45->Size = System::Drawing::Size(93, 48);
			this->taskBox45->TabIndex = 1;
			// 
			// dateBox45
			// 
			this->dateBox45->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox45->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox45->Location = System::Drawing::Point(3, 3);
			this->dateBox45->Name = L"dateBox45";
			this->dateBox45->Size = System::Drawing::Size(93, 14);
			this->dateBox45->TabIndex = 0;
			// 
			// table44
			// 
			this->table44->ColumnCount = 1;
			this->table44->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table44->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table44->Controls->Add(this->taskBox44, 0, 1);
			this->table44->Controls->Add(this->dateBox44, 0, 0);
			this->table44->Location = System::Drawing::Point(324, 290);
			this->table44->Name = L"table44";
			this->table44->RowCount = 2;
			this->table44->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table44->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table44->Size = System::Drawing::Size(99, 73);
			this->table44->TabIndex = 32;
			// 
			// taskBox44
			// 
			this->taskBox44->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox44->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox44->Location = System::Drawing::Point(3, 22);
			this->taskBox44->Multiline = true;
			this->taskBox44->Name = L"taskBox44";
			this->taskBox44->Size = System::Drawing::Size(93, 48);
			this->taskBox44->TabIndex = 1;
			// 
			// dateBox44
			// 
			this->dateBox44->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox44->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox44->Location = System::Drawing::Point(3, 3);
			this->dateBox44->Name = L"dateBox44";
			this->dateBox44->Size = System::Drawing::Size(93, 14);
			this->dateBox44->TabIndex = 0;
			// 
			// table43
			// 
			this->table43->ColumnCount = 1;
			this->table43->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table43->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table43->Controls->Add(this->taskBox43, 0, 1);
			this->table43->Controls->Add(this->dateBox43, 0, 0);
			this->table43->Location = System::Drawing::Point(217, 290);
			this->table43->Name = L"table43";
			this->table43->RowCount = 2;
			this->table43->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table43->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table43->Size = System::Drawing::Size(99, 73);
			this->table43->TabIndex = 31;
			// 
			// taskBox43
			// 
			this->taskBox43->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox43->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox43->Location = System::Drawing::Point(3, 22);
			this->taskBox43->Multiline = true;
			this->taskBox43->Name = L"taskBox43";
			this->taskBox43->Size = System::Drawing::Size(93, 48);
			this->taskBox43->TabIndex = 1;
			// 
			// dateBox43
			// 
			this->dateBox43->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox43->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox43->Location = System::Drawing::Point(3, 3);
			this->dateBox43->Name = L"dateBox43";
			this->dateBox43->Size = System::Drawing::Size(93, 14);
			this->dateBox43->TabIndex = 0;
			// 
			// table42
			// 
			this->table42->ColumnCount = 1;
			this->table42->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table42->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table42->Controls->Add(this->taskBox42, 0, 1);
			this->table42->Controls->Add(this->dateBox42, 0, 0);
			this->table42->Location = System::Drawing::Point(110, 290);
			this->table42->Name = L"table42";
			this->table42->RowCount = 2;
			this->table42->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table42->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table42->Size = System::Drawing::Size(99, 73);
			this->table42->TabIndex = 30;
			// 
			// taskBox42
			// 
			this->taskBox42->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox42->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox42->Location = System::Drawing::Point(3, 22);
			this->taskBox42->Multiline = true;
			this->taskBox42->Name = L"taskBox42";
			this->taskBox42->Size = System::Drawing::Size(93, 48);
			this->taskBox42->TabIndex = 1;
			// 
			// dateBox42
			// 
			this->dateBox42->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox42->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox42->Location = System::Drawing::Point(3, 3);
			this->dateBox42->Name = L"dateBox42";
			this->dateBox42->Size = System::Drawing::Size(93, 14);
			this->dateBox42->TabIndex = 0;
			// 
			// tableLayoutPanel22
			// 
			this->tableLayoutPanel22->ColumnCount = 1;
			this->tableLayoutPanel22->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35.52632F)));
			this->tableLayoutPanel22->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				64.47369F)));
			this->tableLayoutPanel22->Controls->Add(this->taskBox41, 0, 1);
			this->tableLayoutPanel22->Controls->Add(this->dateBox41, 0, 0);
			this->tableLayoutPanel22->Location = System::Drawing::Point(4, 290);
			this->tableLayoutPanel22->Name = L"tableLayoutPanel22";
			this->tableLayoutPanel22->RowCount = 2;
			this->tableLayoutPanel22->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->tableLayoutPanel22->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->tableLayoutPanel22->Size = System::Drawing::Size(99, 73);
			this->tableLayoutPanel22->TabIndex = 29;
			// 
			// taskBox41
			// 
			this->taskBox41->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox41->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox41->Location = System::Drawing::Point(3, 22);
			this->taskBox41->Multiline = true;
			this->taskBox41->Name = L"taskBox41";
			this->taskBox41->Size = System::Drawing::Size(93, 48);
			this->taskBox41->TabIndex = 1;
			// 
			// dateBox41
			// 
			this->dateBox41->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox41->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox41->Location = System::Drawing::Point(3, 3);
			this->dateBox41->Name = L"dateBox41";
			this->dateBox41->Size = System::Drawing::Size(93, 14);
			this->dateBox41->TabIndex = 0;
			// 
			// table37
			// 
			this->table37->ColumnCount = 1;
			this->table37->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table37->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table37->Controls->Add(this->taskBox37, 0, 1);
			this->table37->Controls->Add(this->dateBox37, 0, 0);
			this->table37->Location = System::Drawing::Point(645, 209);
			this->table37->Name = L"table37";
			this->table37->RowCount = 2;
			this->table37->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table37->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table37->Size = System::Drawing::Size(99, 73);
			this->table37->TabIndex = 28;
			// 
			// taskBox37
			// 
			this->taskBox37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox37->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox37->Location = System::Drawing::Point(3, 22);
			this->taskBox37->Multiline = true;
			this->taskBox37->Name = L"taskBox37";
			this->taskBox37->Size = System::Drawing::Size(93, 48);
			this->taskBox37->TabIndex = 1;
			// 
			// dateBox37
			// 
			this->dateBox37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox37->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox37->Location = System::Drawing::Point(3, 3);
			this->dateBox37->Name = L"dateBox37";
			this->dateBox37->Size = System::Drawing::Size(93, 14);
			this->dateBox37->TabIndex = 0;
			// 
			// table36
			// 
			this->table36->ColumnCount = 1;
			this->table36->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table36->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table36->Controls->Add(this->taskBox36, 0, 1);
			this->table36->Controls->Add(this->dateBox36, 0, 0);
			this->table36->Location = System::Drawing::Point(538, 209);
			this->table36->Name = L"table36";
			this->table36->RowCount = 2;
			this->table36->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table36->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table36->Size = System::Drawing::Size(99, 73);
			this->table36->TabIndex = 27;
			// 
			// taskBox36
			// 
			this->taskBox36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox36->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox36->Location = System::Drawing::Point(3, 22);
			this->taskBox36->Multiline = true;
			this->taskBox36->Name = L"taskBox36";
			this->taskBox36->Size = System::Drawing::Size(93, 48);
			this->taskBox36->TabIndex = 1;
			// 
			// dateBox36
			// 
			this->dateBox36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox36->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox36->Location = System::Drawing::Point(3, 3);
			this->dateBox36->Name = L"dateBox36";
			this->dateBox36->Size = System::Drawing::Size(93, 14);
			this->dateBox36->TabIndex = 0;
			// 
			// table35
			// 
			this->table35->ColumnCount = 1;
			this->table35->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table35->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table35->Controls->Add(this->taskBox35, 0, 1);
			this->table35->Controls->Add(this->dateBox35, 0, 0);
			this->table35->Location = System::Drawing::Point(431, 209);
			this->table35->Name = L"table35";
			this->table35->RowCount = 2;
			this->table35->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table35->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table35->Size = System::Drawing::Size(99, 73);
			this->table35->TabIndex = 26;
			// 
			// taskBox35
			// 
			this->taskBox35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox35->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox35->Location = System::Drawing::Point(3, 22);
			this->taskBox35->Multiline = true;
			this->taskBox35->Name = L"taskBox35";
			this->taskBox35->Size = System::Drawing::Size(93, 48);
			this->taskBox35->TabIndex = 1;
			// 
			// dateBox35
			// 
			this->dateBox35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox35->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox35->Location = System::Drawing::Point(3, 3);
			this->dateBox35->Name = L"dateBox35";
			this->dateBox35->Size = System::Drawing::Size(93, 14);
			this->dateBox35->TabIndex = 0;
			// 
			// table34
			// 
			this->table34->ColumnCount = 1;
			this->table34->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table34->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table34->Controls->Add(this->taskBox34, 0, 1);
			this->table34->Controls->Add(this->dateBox34, 0, 0);
			this->table34->Location = System::Drawing::Point(324, 209);
			this->table34->Name = L"table34";
			this->table34->RowCount = 2;
			this->table34->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table34->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table34->Size = System::Drawing::Size(99, 73);
			this->table34->TabIndex = 25;
			// 
			// taskBox34
			// 
			this->taskBox34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox34->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox34->Location = System::Drawing::Point(3, 22);
			this->taskBox34->Multiline = true;
			this->taskBox34->Name = L"taskBox34";
			this->taskBox34->Size = System::Drawing::Size(93, 48);
			this->taskBox34->TabIndex = 1;
			// 
			// dateBox34
			// 
			this->dateBox34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox34->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox34->Location = System::Drawing::Point(3, 3);
			this->dateBox34->Name = L"dateBox34";
			this->dateBox34->Size = System::Drawing::Size(93, 14);
			this->dateBox34->TabIndex = 0;
			// 
			// table33
			// 
			this->table33->ColumnCount = 1;
			this->table33->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table33->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table33->Controls->Add(this->taskBox33, 0, 1);
			this->table33->Controls->Add(this->dateBox33, 0, 0);
			this->table33->Location = System::Drawing::Point(217, 209);
			this->table33->Name = L"table33";
			this->table33->RowCount = 2;
			this->table33->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table33->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table33->Size = System::Drawing::Size(99, 73);
			this->table33->TabIndex = 24;
			// 
			// taskBox33
			// 
			this->taskBox33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox33->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox33->Location = System::Drawing::Point(3, 22);
			this->taskBox33->Multiline = true;
			this->taskBox33->Name = L"taskBox33";
			this->taskBox33->Size = System::Drawing::Size(93, 48);
			this->taskBox33->TabIndex = 1;
			// 
			// dateBox33
			// 
			this->dateBox33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox33->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox33->Location = System::Drawing::Point(3, 3);
			this->dateBox33->Name = L"dateBox33";
			this->dateBox33->Size = System::Drawing::Size(93, 14);
			this->dateBox33->TabIndex = 0;
			// 
			// table32
			// 
			this->table32->ColumnCount = 1;
			this->table32->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table32->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table32->Controls->Add(this->taskBox32, 0, 1);
			this->table32->Controls->Add(this->dateBox32, 0, 0);
			this->table32->Location = System::Drawing::Point(110, 209);
			this->table32->Name = L"table32";
			this->table32->RowCount = 2;
			this->table32->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table32->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table32->Size = System::Drawing::Size(99, 73);
			this->table32->TabIndex = 23;
			// 
			// taskBox32
			// 
			this->taskBox32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox32->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox32->Location = System::Drawing::Point(3, 22);
			this->taskBox32->Multiline = true;
			this->taskBox32->Name = L"taskBox32";
			this->taskBox32->Size = System::Drawing::Size(93, 48);
			this->taskBox32->TabIndex = 1;
			// 
			// dateBox32
			// 
			this->dateBox32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox32->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox32->Location = System::Drawing::Point(3, 3);
			this->dateBox32->Name = L"dateBox32";
			this->dateBox32->Size = System::Drawing::Size(93, 14);
			this->dateBox32->TabIndex = 0;
			// 
			// table31
			// 
			this->table31->ColumnCount = 1;
			this->table31->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table31->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table31->Controls->Add(this->taskBox31, 0, 1);
			this->table31->Controls->Add(this->dateBox31, 0, 0);
			this->table31->Location = System::Drawing::Point(4, 209);
			this->table31->Name = L"table31";
			this->table31->RowCount = 2;
			this->table31->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table31->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table31->Size = System::Drawing::Size(99, 73);
			this->table31->TabIndex = 22;
			// 
			// taskBox31
			// 
			this->taskBox31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox31->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox31->Location = System::Drawing::Point(3, 22);
			this->taskBox31->Multiline = true;
			this->taskBox31->Name = L"taskBox31";
			this->taskBox31->Size = System::Drawing::Size(93, 48);
			this->taskBox31->TabIndex = 1;
			// 
			// dateBox31
			// 
			this->dateBox31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox31->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox31->Location = System::Drawing::Point(3, 3);
			this->dateBox31->Name = L"dateBox31";
			this->dateBox31->Size = System::Drawing::Size(93, 14);
			this->dateBox31->TabIndex = 0;
			// 
			// table27
			// 
			this->table27->ColumnCount = 1;
			this->table27->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table27->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table27->Controls->Add(this->taskBox27, 0, 1);
			this->table27->Controls->Add(this->dateBox27, 0, 0);
			this->table27->Location = System::Drawing::Point(645, 128);
			this->table27->Name = L"table27";
			this->table27->RowCount = 2;
			this->table27->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table27->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table27->Size = System::Drawing::Size(99, 73);
			this->table27->TabIndex = 21;
			// 
			// taskBox27
			// 
			this->taskBox27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox27->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox27->Location = System::Drawing::Point(3, 22);
			this->taskBox27->Multiline = true;
			this->taskBox27->Name = L"taskBox27";
			this->taskBox27->Size = System::Drawing::Size(93, 48);
			this->taskBox27->TabIndex = 1;
			// 
			// dateBox27
			// 
			this->dateBox27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox27->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox27->Location = System::Drawing::Point(3, 3);
			this->dateBox27->Name = L"dateBox27";
			this->dateBox27->Size = System::Drawing::Size(93, 14);
			this->dateBox27->TabIndex = 0;
			// 
			// table26
			// 
			this->table26->ColumnCount = 1;
			this->table26->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table26->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table26->Controls->Add(this->taskBox26, 0, 1);
			this->table26->Controls->Add(this->dateBox26, 0, 0);
			this->table26->Location = System::Drawing::Point(538, 128);
			this->table26->Name = L"table26";
			this->table26->RowCount = 2;
			this->table26->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table26->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table26->Size = System::Drawing::Size(99, 73);
			this->table26->TabIndex = 20;
			// 
			// taskBox26
			// 
			this->taskBox26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox26->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox26->Location = System::Drawing::Point(3, 22);
			this->taskBox26->Multiline = true;
			this->taskBox26->Name = L"taskBox26";
			this->taskBox26->Size = System::Drawing::Size(93, 48);
			this->taskBox26->TabIndex = 1;
			// 
			// dateBox26
			// 
			this->dateBox26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox26->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox26->Location = System::Drawing::Point(3, 3);
			this->dateBox26->Name = L"dateBox26";
			this->dateBox26->Size = System::Drawing::Size(93, 14);
			this->dateBox26->TabIndex = 0;
			// 
			// table25
			// 
			this->table25->ColumnCount = 1;
			this->table25->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table25->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table25->Controls->Add(this->taskBox25, 0, 1);
			this->table25->Controls->Add(this->dateBox25, 0, 0);
			this->table25->Location = System::Drawing::Point(431, 128);
			this->table25->Name = L"table25";
			this->table25->RowCount = 2;
			this->table25->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table25->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table25->Size = System::Drawing::Size(99, 73);
			this->table25->TabIndex = 19;
			// 
			// taskBox25
			// 
			this->taskBox25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox25->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox25->Location = System::Drawing::Point(3, 22);
			this->taskBox25->Multiline = true;
			this->taskBox25->Name = L"taskBox25";
			this->taskBox25->Size = System::Drawing::Size(93, 48);
			this->taskBox25->TabIndex = 1;
			// 
			// dateBox25
			// 
			this->dateBox25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox25->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox25->Location = System::Drawing::Point(3, 3);
			this->dateBox25->Name = L"dateBox25";
			this->dateBox25->Size = System::Drawing::Size(93, 14);
			this->dateBox25->TabIndex = 0;
			// 
			// table24
			// 
			this->table24->ColumnCount = 1;
			this->table24->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table24->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table24->Controls->Add(this->taskBox24, 0, 1);
			this->table24->Controls->Add(this->dateBox24, 0, 0);
			this->table24->Location = System::Drawing::Point(324, 128);
			this->table24->Name = L"table24";
			this->table24->RowCount = 2;
			this->table24->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table24->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table24->Size = System::Drawing::Size(99, 73);
			this->table24->TabIndex = 18;
			// 
			// taskBox24
			// 
			this->taskBox24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox24->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox24->Location = System::Drawing::Point(3, 22);
			this->taskBox24->Multiline = true;
			this->taskBox24->Name = L"taskBox24";
			this->taskBox24->Size = System::Drawing::Size(93, 48);
			this->taskBox24->TabIndex = 1;
			// 
			// dateBox24
			// 
			this->dateBox24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox24->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox24->Location = System::Drawing::Point(3, 3);
			this->dateBox24->Name = L"dateBox24";
			this->dateBox24->Size = System::Drawing::Size(93, 14);
			this->dateBox24->TabIndex = 0;
			// 
			// table23
			// 
			this->table23->ColumnCount = 1;
			this->table23->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table23->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table23->Controls->Add(this->taskBox23, 0, 1);
			this->table23->Controls->Add(this->dateBox23, 0, 0);
			this->table23->Location = System::Drawing::Point(217, 128);
			this->table23->Name = L"table23";
			this->table23->RowCount = 2;
			this->table23->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table23->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table23->Size = System::Drawing::Size(99, 73);
			this->table23->TabIndex = 17;
			// 
			// taskBox23
			// 
			this->taskBox23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox23->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox23->Location = System::Drawing::Point(3, 22);
			this->taskBox23->Multiline = true;
			this->taskBox23->Name = L"taskBox23";
			this->taskBox23->Size = System::Drawing::Size(93, 48);
			this->taskBox23->TabIndex = 1;
			// 
			// dateBox23
			// 
			this->dateBox23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox23->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox23->Location = System::Drawing::Point(3, 3);
			this->dateBox23->Name = L"dateBox23";
			this->dateBox23->Size = System::Drawing::Size(93, 14);
			this->dateBox23->TabIndex = 0;
			// 
			// table22
			// 
			this->table22->ColumnCount = 1;
			this->table22->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table22->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table22->Controls->Add(this->taskBox22, 0, 1);
			this->table22->Controls->Add(this->dateBox22, 0, 0);
			this->table22->Location = System::Drawing::Point(110, 128);
			this->table22->Name = L"table22";
			this->table22->RowCount = 2;
			this->table22->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table22->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table22->Size = System::Drawing::Size(99, 73);
			this->table22->TabIndex = 16;
			// 
			// taskBox22
			// 
			this->taskBox22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox22->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7));
			this->taskBox22->Location = System::Drawing::Point(3, 22);
			this->taskBox22->Multiline = true;
			this->taskBox22->Name = L"taskBox22";
			this->taskBox22->Size = System::Drawing::Size(93, 48);
			this->taskBox22->TabIndex = 1;
			// 
			// dateBox22
			// 
			this->dateBox22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox22->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox22->Location = System::Drawing::Point(3, 3);
			this->dateBox22->Name = L"dateBox22";
			this->dateBox22->Size = System::Drawing::Size(93, 14);
			this->dateBox22->TabIndex = 0;
			// 
			// table21
			// 
			this->table21->ColumnCount = 1;
			this->table21->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table21->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table21->Controls->Add(this->taskBox21, 0, 1);
			this->table21->Controls->Add(this->dateBox21, 0, 0);
			this->table21->Location = System::Drawing::Point(4, 128);
			this->table21->Name = L"table21";
			this->table21->RowCount = 2;
			this->table21->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table21->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table21->Size = System::Drawing::Size(99, 73);
			this->table21->TabIndex = 15;
			// 
			// taskBox21
			// 
			this->taskBox21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox21->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox21->Location = System::Drawing::Point(3, 22);
			this->taskBox21->Multiline = true;
			this->taskBox21->Name = L"taskBox21";
			this->taskBox21->Size = System::Drawing::Size(93, 48);
			this->taskBox21->TabIndex = 1;
			// 
			// dateBox21
			// 
			this->dateBox21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox21->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox21->Location = System::Drawing::Point(3, 3);
			this->dateBox21->Name = L"dateBox21";
			this->dateBox21->Size = System::Drawing::Size(93, 14);
			this->dateBox21->TabIndex = 0;
			// 
			// table17
			// 
			this->table17->ColumnCount = 1;
			this->table17->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table17->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table17->Controls->Add(this->taskBox17, 0, 1);
			this->table17->Controls->Add(this->dateBox17, 0, 0);
			this->table17->Location = System::Drawing::Point(645, 47);
			this->table17->Name = L"table17";
			this->table17->RowCount = 2;
			this->table17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.65753F)));
			this->table17->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 75.34247F)));
			this->table17->Size = System::Drawing::Size(99, 73);
			this->table17->TabIndex = 14;
			// 
			// taskBox17
			// 
			this->taskBox17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox17->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox17->Location = System::Drawing::Point(3, 20);
			this->taskBox17->Multiline = true;
			this->taskBox17->Name = L"taskBox17";
			this->taskBox17->Size = System::Drawing::Size(93, 50);
			this->taskBox17->TabIndex = 1;
			// 
			// dateBox17
			// 
			this->dateBox17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox17->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox17->Location = System::Drawing::Point(3, 3);
			this->dateBox17->Name = L"dateBox17";
			this->dateBox17->Size = System::Drawing::Size(93, 14);
			this->dateBox17->TabIndex = 0;
			// 
			// table16
			// 
			this->table16->ColumnCount = 1;
			this->table16->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table16->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table16->Controls->Add(this->taskBox16, 0, 1);
			this->table16->Controls->Add(this->dateBox16, 0, 0);
			this->table16->Location = System::Drawing::Point(538, 47);
			this->table16->Name = L"table16";
			this->table16->RowCount = 2;
			this->table16->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table16->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table16->Size = System::Drawing::Size(99, 73);
			this->table16->TabIndex = 13;
			// 
			// taskBox16
			// 
			this->taskBox16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox16->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox16->Location = System::Drawing::Point(3, 22);
			this->taskBox16->Multiline = true;
			this->taskBox16->Name = L"taskBox16";
			this->taskBox16->Size = System::Drawing::Size(93, 48);
			this->taskBox16->TabIndex = 1;
			// 
			// dateBox16
			// 
			this->dateBox16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox16->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox16->Location = System::Drawing::Point(3, 3);
			this->dateBox16->Name = L"dateBox16";
			this->dateBox16->Size = System::Drawing::Size(93, 14);
			this->dateBox16->TabIndex = 0;
			// 
			// table15
			// 
			this->table15->ColumnCount = 1;
			this->table15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table15->Controls->Add(this->taskBox15, 0, 1);
			this->table15->Controls->Add(this->dateBox15, 0, 0);
			this->table15->Location = System::Drawing::Point(431, 47);
			this->table15->Name = L"table15";
			this->table15->RowCount = 2;
			this->table15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table15->Size = System::Drawing::Size(99, 73);
			this->table15->TabIndex = 12;
			// 
			// taskBox15
			// 
			this->taskBox15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox15->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox15->Location = System::Drawing::Point(3, 22);
			this->taskBox15->Multiline = true;
			this->taskBox15->Name = L"taskBox15";
			this->taskBox15->Size = System::Drawing::Size(93, 48);
			this->taskBox15->TabIndex = 1;
			// 
			// dateBox15
			// 
			this->dateBox15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox15->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox15->Location = System::Drawing::Point(3, 3);
			this->dateBox15->Name = L"dateBox15";
			this->dateBox15->Size = System::Drawing::Size(93, 14);
			this->dateBox15->TabIndex = 0;
			// 
			// table14
			// 
			this->table14->ColumnCount = 1;
			this->table14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table14->Controls->Add(this->taskBox14, 0, 1);
			this->table14->Controls->Add(this->dateBox14, 0, 0);
			this->table14->Location = System::Drawing::Point(324, 47);
			this->table14->Name = L"table14";
			this->table14->RowCount = 2;
			this->table14->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table14->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table14->Size = System::Drawing::Size(99, 73);
			this->table14->TabIndex = 11;
			// 
			// taskBox14
			// 
			this->taskBox14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox14->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox14->Location = System::Drawing::Point(3, 22);
			this->taskBox14->Multiline = true;
			this->taskBox14->Name = L"taskBox14";
			this->taskBox14->Size = System::Drawing::Size(93, 48);
			this->taskBox14->TabIndex = 1;
			// 
			// dateBox14
			// 
			this->dateBox14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox14->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox14->Location = System::Drawing::Point(3, 3);
			this->dateBox14->Name = L"dateBox14";
			this->dateBox14->Size = System::Drawing::Size(93, 14);
			this->dateBox14->TabIndex = 0;
			// 
			// table13
			// 
			this->table13->ColumnCount = 1;
			this->table13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table13->Controls->Add(this->taskBox13, 0, 1);
			this->table13->Controls->Add(this->dateBox13, 0, 0);
			this->table13->Location = System::Drawing::Point(217, 47);
			this->table13->Name = L"table13";
			this->table13->RowCount = 2;
			this->table13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table13->Size = System::Drawing::Size(99, 73);
			this->table13->TabIndex = 10;
			// 
			// taskBox13
			// 
			this->taskBox13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox13->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox13->Location = System::Drawing::Point(3, 22);
			this->taskBox13->Multiline = true;
			this->taskBox13->Name = L"taskBox13";
			this->taskBox13->Size = System::Drawing::Size(93, 48);
			this->taskBox13->TabIndex = 1;
			// 
			// dateBox13
			// 
			this->dateBox13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox13->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox13->Location = System::Drawing::Point(3, 3);
			this->dateBox13->Name = L"dateBox13";
			this->dateBox13->Size = System::Drawing::Size(93, 14);
			this->dateBox13->TabIndex = 0;
			// 
			// table12
			// 
			this->table12->ColumnCount = 1;
			this->table12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table12->Controls->Add(this->taskBox12, 0, 1);
			this->table12->Controls->Add(this->dateBox12, 0, 0);
			this->table12->Location = System::Drawing::Point(110, 47);
			this->table12->Name = L"table12";
			this->table12->RowCount = 2;
			this->table12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table12->Size = System::Drawing::Size(99, 73);
			this->table12->TabIndex = 9;
			// 
			// taskBox12
			// 
			this->taskBox12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox12->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox12->Location = System::Drawing::Point(3, 22);
			this->taskBox12->Multiline = true;
			this->taskBox12->Name = L"taskBox12";
			this->taskBox12->Size = System::Drawing::Size(93, 48);
			this->taskBox12->TabIndex = 1;
			// 
			// dateBox12
			// 
			this->dateBox12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox12->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox12->Location = System::Drawing::Point(3, 3);
			this->dateBox12->Name = L"dateBox12";
			this->dateBox12->Size = System::Drawing::Size(93, 14);
			this->dateBox12->TabIndex = 0;
			// 
			// dayTxtBlkSat
			// 
			this->dayTxtBlkSat->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dayTxtBlkSat->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dayTxtBlkSat->Location = System::Drawing::Point(645, 4);
			this->dayTxtBlkSat->Name = L"dayTxtBlkSat";
			this->dayTxtBlkSat->ReadOnly = true;
			this->dayTxtBlkSat->Size = System::Drawing::Size(80, 19);
			this->dayTxtBlkSat->TabIndex = 6;
			this->dayTxtBlkSat->Text = L"Sat";
			this->dayTxtBlkSat->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// dayTxtBlkFri
			// 
			this->dayTxtBlkFri->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dayTxtBlkFri->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dayTxtBlkFri->Location = System::Drawing::Point(538, 4);
			this->dayTxtBlkFri->Name = L"dayTxtBlkFri";
			this->dayTxtBlkFri->ReadOnly = true;
			this->dayTxtBlkFri->Size = System::Drawing::Size(76, 19);
			this->dayTxtBlkFri->TabIndex = 5;
			this->dayTxtBlkFri->Text = L"Fri";
			this->dayTxtBlkFri->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->dayTxtBlkFri->TextChanged += gcnew System::EventHandler(this, &MonthForm::textBox5_TextChanged);
			// 
			// dayTxtBlkThur
			// 
			this->dayTxtBlkThur->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dayTxtBlkThur->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dayTxtBlkThur->Location = System::Drawing::Point(431, 4);
			this->dayTxtBlkThur->Name = L"dayTxtBlkThur";
			this->dayTxtBlkThur->ReadOnly = true;
			this->dayTxtBlkThur->Size = System::Drawing::Size(76, 19);
			this->dayTxtBlkThur->TabIndex = 4;
			this->dayTxtBlkThur->Text = L"Thu";
			this->dayTxtBlkThur->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// dayTxtBlkTue
			// 
			this->dayTxtBlkTue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dayTxtBlkTue->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dayTxtBlkTue->Location = System::Drawing::Point(217, 4);
			this->dayTxtBlkTue->Name = L"dayTxtBlkTue";
			this->dayTxtBlkTue->ReadOnly = true;
			this->dayTxtBlkTue->Size = System::Drawing::Size(76, 19);
			this->dayTxtBlkTue->TabIndex = 2;
			this->dayTxtBlkTue->Text = L"Tue";
			this->dayTxtBlkTue->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// dayTxtBlkSun
			// 
			this->dayTxtBlkSun->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dayTxtBlkSun->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dayTxtBlkSun->Location = System::Drawing::Point(4, 4);
			this->dayTxtBlkSun->Name = L"dayTxtBlkSun";
			this->dayTxtBlkSun->ReadOnly = true;
			this->dayTxtBlkSun->Size = System::Drawing::Size(76, 19);
			this->dayTxtBlkSun->TabIndex = 0;
			this->dayTxtBlkSun->Text = L"Sun";
			this->dayTxtBlkSun->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->dayTxtBlkSun->TextChanged += gcnew System::EventHandler(this, &MonthForm::textBox1_TextChanged);
			// 
			// dayTxtBlkMon
			// 
			this->dayTxtBlkMon->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dayTxtBlkMon->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dayTxtBlkMon->Location = System::Drawing::Point(110, 4);
			this->dayTxtBlkMon->Name = L"dayTxtBlkMon";
			this->dayTxtBlkMon->ReadOnly = true;
			this->dayTxtBlkMon->Size = System::Drawing::Size(76, 19);
			this->dayTxtBlkMon->TabIndex = 1;
			this->dayTxtBlkMon->Text = L"Mon";
			this->dayTxtBlkMon->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// table11
			// 
			this->table11->ColumnCount = 1;
			this->table11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.52632F)));
			this->table11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.47369F)));
			this->table11->Controls->Add(this->taskBox11, 0, 1);
			this->table11->Controls->Add(this->dateBox11, 0, 0);
			this->table11->Location = System::Drawing::Point(4, 47);
			this->table11->Name = L"table11";
			this->table11->RowCount = 2;
			this->table11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.0274F)));
			this->table11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.9726F)));
			this->table11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->table11->Size = System::Drawing::Size(99, 73);
			this->table11->TabIndex = 8;
			// 
			// taskBox11
			// 
			this->taskBox11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->taskBox11->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taskBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->taskBox11->Location = System::Drawing::Point(3, 22);
			this->taskBox11->Multiline = true;
			this->taskBox11->Name = L"taskBox11";
			this->taskBox11->Size = System::Drawing::Size(93, 48);
			this->taskBox11->TabIndex = 1;
			// 
			// dateBox11
			// 
			this->dateBox11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dateBox11->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dateBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->dateBox11->Location = System::Drawing::Point(3, 3);
			this->dateBox11->Name = L"dateBox11";
			this->dateBox11->Size = System::Drawing::Size(27, 14);
			this->dateBox11->TabIndex = 0;
			// 
			// dayTxtBlkWed
			// 
			this->dayTxtBlkWed->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dayTxtBlkWed->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dayTxtBlkWed->Location = System::Drawing::Point(324, 4);
			this->dayTxtBlkWed->Name = L"dayTxtBlkWed";
			this->dayTxtBlkWed->ReadOnly = true;
			this->dayTxtBlkWed->Size = System::Drawing::Size(76, 19);
			this->dayTxtBlkWed->TabIndex = 3;
			this->dayTxtBlkWed->Text = L"Wed";
			this->dayTxtBlkWed->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// userInputBox
			// 
			this->userInputBox->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(7) {
				L"add", L"edit", L"delete",
					L"show", L"redo", L"undo", L"search"
			});
			this->userInputBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Append;
			this->userInputBox->BackColor = System::Drawing::Color::White;
			this->userInputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->userInputBox->Location = System::Drawing::Point(304, 524);
			this->userInputBox->Name = L"userInputBox";
			this->userInputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->userInputBox->Size = System::Drawing::Size(750, 29);
			this->userInputBox->TabIndex = 1;
			this->userInputBox->TextChanged += gcnew System::EventHandler(this, &MonthForm::userInputBox_TextChanged);
			this->userInputBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MonthForm::ctrlHold);
			this->userInputBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MonthForm::userEnter);
			// 
			// monthFormTitle
			// 
			this->monthFormTitle->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->monthFormTitle->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->monthFormTitle->Enabled = false;
			this->monthFormTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->monthFormTitle->Location = System::Drawing::Point(556, 6);
			this->monthFormTitle->Name = L"monthFormTitle";
			this->monthFormTitle->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->monthFormTitle->Size = System::Drawing::Size(255, 25);
			this->monthFormTitle->TabIndex = 2;
			this->monthFormTitle->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(12, 37);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(273, 516);
			this->textBox5->TabIndex = 3;
			// 
			// showBox
			// 
			this->showBox->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->showBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->showBox->Enabled = false;
			this->showBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->showBox->ForeColor = System::Drawing::Color::Black;
			this->showBox->Location = System::Drawing::Point(12, 3);
			this->showBox->Name = L"showBox";
			this->showBox->ReadOnly = true;
			this->showBox->Size = System::Drawing::Size(273, 25);
			this->showBox->TabIndex = 4;
			this->showBox->Text = L"Todo Tasks";
			this->showBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->textBox1->Location = System::Drawing::Point(304, 502);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(749, 16);
			this->textBox1->TabIndex = 5;
			// 
			// resetButton
			// 
			this->resetButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->resetButton->Location = System::Drawing::Point(1013, 6);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(32, 23);
			this->resetButton->TabIndex = 6;
			this->resetButton->Text = L"DV";
			this->resetButton->UseVisualStyleBackColor = false;
			this->resetButton->Click += gcnew System::EventHandler(this, &MonthForm::defaultView);
			// 
			// MonthForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1057, 565);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->showBox);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->monthFormTitle);
			this->Controls->Add(this->userInputBox);
			this->Controls->Add(this->monthPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MonthForm";
			this->Text = L"ComCal";
			this->monthPanel->ResumeLayout(false);
			this->monthPanel->PerformLayout();
			this->table51->ResumeLayout(false);
			this->table51->PerformLayout();
			this->table57->ResumeLayout(false);
			this->table57->PerformLayout();
			this->table56->ResumeLayout(false);
			this->table56->PerformLayout();
			this->table55->ResumeLayout(false);
			this->table55->PerformLayout();
			this->table54->ResumeLayout(false);
			this->table54->PerformLayout();
			this->table53->ResumeLayout(false);
			this->table53->PerformLayout();
			this->table52->ResumeLayout(false);
			this->table52->PerformLayout();
			this->table47->ResumeLayout(false);
			this->table47->PerformLayout();
			this->table46->ResumeLayout(false);
			this->table46->PerformLayout();
			this->tableLayoutPanel26->ResumeLayout(false);
			this->tableLayoutPanel26->PerformLayout();
			this->table44->ResumeLayout(false);
			this->table44->PerformLayout();
			this->table43->ResumeLayout(false);
			this->table43->PerformLayout();
			this->table42->ResumeLayout(false);
			this->table42->PerformLayout();
			this->tableLayoutPanel22->ResumeLayout(false);
			this->tableLayoutPanel22->PerformLayout();
			this->table37->ResumeLayout(false);
			this->table37->PerformLayout();
			this->table36->ResumeLayout(false);
			this->table36->PerformLayout();
			this->table35->ResumeLayout(false);
			this->table35->PerformLayout();
			this->table34->ResumeLayout(false);
			this->table34->PerformLayout();
			this->table33->ResumeLayout(false);
			this->table33->PerformLayout();
			this->table32->ResumeLayout(false);
			this->table32->PerformLayout();
			this->table31->ResumeLayout(false);
			this->table31->PerformLayout();
			this->table27->ResumeLayout(false);
			this->table27->PerformLayout();
			this->table26->ResumeLayout(false);
			this->table26->PerformLayout();
			this->table25->ResumeLayout(false);
			this->table25->PerformLayout();
			this->table24->ResumeLayout(false);
			this->table24->PerformLayout();
			this->table23->ResumeLayout(false);
			this->table23->PerformLayout();
			this->table22->ResumeLayout(false);
			this->table22->PerformLayout();
			this->table21->ResumeLayout(false);
			this->table21->PerformLayout();
			this->table17->ResumeLayout(false);
			this->table17->PerformLayout();
			this->table16->ResumeLayout(false);
			this->table16->PerformLayout();
			this->table15->ResumeLayout(false);
			this->table15->PerformLayout();
			this->table14->ResumeLayout(false);
			this->table14->PerformLayout();
			this->table13->ResumeLayout(false);
			this->table13->PerformLayout();
			this->table12->ResumeLayout(false);
			this->table12->PerformLayout();
			this->table11->ResumeLayout(false);
			this->table11->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion  

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {}
	private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {}
	private: System::Void userInputBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {}
	private: System::Void monthPanel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {}

	private: System::Void userEnter(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);

	
private: System::Void ctrlHold(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
private: System::Void defaultView(System::Object^  sender, System::EventArgs^  e);

}; //end MonthForm class
} //end of ComCal_v01 namespace