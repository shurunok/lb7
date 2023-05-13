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
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
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
			this->label1->Text = L"Введіть текст";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(52, 192);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(232, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Обчислити довжину рядка";
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
			this->label2->Text = L"Результат";
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
		cout << "Введіть рядок: ";
		getline(cin, input);

		// Перетворення малих літер на великі
		for (char& c : input) {
			if (islower(c)) {
				c = toupper(c);
			}
		}

		cout << "Перетворений рядок: " << input << endl;

		return 0;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		string fullName;
		cout << "Введіть прізвище, ім'я та по батькові студента: ";
		getline(cin, fullName);

		// Визначення довжини прізвища, імені та по батькові
		size_t lastNameLength = fullName.find(' ');
		size_t firstNameLength = fullName.find(' ', lastNameLength + 1) - lastNameLength - 1;
		size_t middleNameLength = fullName.length() - lastNameLength - firstNameLength - 2;

		// Визначення довжини рядка, що об'єднує всі слова в одне
		size_t totalLength = fullName.length() - 2;

		cout << "Довжина прізвища: " << lastNameLength << endl;
		cout << "Довжина імені: " << firstNameLength << endl;
		cout << "Довжина по батькові: " << middleNameLength << endl;
		cout << "Довжина рядка, що об'єднує всі слова: " << totalLength << endl;

		// Видрук прізвища та ініціалів
		string lastName = fullName.substr(0, lastNameLength);
		string firstName = fullName.substr(lastNameLength + 1, firstNameLength);
		string middleName = fullName.substr(lastNameLength + 2 + firstNameLength, middleNameLength);
		cout << "Прізвище: " << lastName << endl;
		cout << "Ініціали: " << lastName[0] << "." << firstName[0] << "." << middleName[0] << "." << endl;

		return 0;
	}
	}
};
}
