#pragma once
#include <string>
#include <string>

namespace lb7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(162, 137);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(273, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(49, 140);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"������ �����";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(52, 192);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(232, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"��������� ������� �����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(49, 244);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"���������";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(171, 241);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(521, 406);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		string input;
		cout << "������ �����: ";
		getline(cin, input);

		// ������������ ����� ���� �� �����
		for (char& c : input) {
			if (islower(c)) {
				c = toupper(c);
			}
		}

		cout << "������������ �����: " << input << endl;

		return 0;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		string fullName;
		cout << "������ �������, ��'� �� �� ������� ��������: ";
		getline(cin, fullName);

		// ���������� ������� �������, ���� �� �� �������
		size_t lastNameLength = fullName.find(' ');
		size_t firstNameLength = fullName.find(' ', lastNameLength + 1) - lastNameLength - 1;
		size_t middleNameLength = fullName.length() - lastNameLength - firstNameLength - 2;

		// ���������� ������� �����, �� ��'���� �� ����� � ����
		size_t totalLength = fullName.length() - 2;

		cout << "������� �������: " << lastNameLength << endl;
		cout << "������� ����: " << firstNameLength << endl;
		cout << "������� �� �������: " << middleNameLength << endl;
		cout << "������� �����, �� ��'���� �� �����: " << totalLength << endl;

		// ������ ������� �� �������
		string lastName = fullName.substr(0, lastNameLength);
		string firstName = fullName.substr(lastNameLength + 1, firstNameLength);
		string middleName = fullName.substr(lastNameLength + 2 + firstNameLength, middleNameLength);
		cout << "�������: " << lastName << endl;
		cout << "�������: " << lastName[0] << "." << firstName[0] << "." << middleName[0] << "." << endl;

		return 0;
	}
	}
};
}
