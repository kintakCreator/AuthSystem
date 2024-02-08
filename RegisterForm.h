#pragma once

#include "User.h"

namespace AuthSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// —водка дл€ RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
		{
			InitializeComponent();
			this->CenterToScreen();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::TextBox^ tbEmail;
	private: System::Windows::Forms::TextBox^ tbConfirm;
	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::TextBox^ tbPhone;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->tbConfirm = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->tbPhone = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(33, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Register";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(129, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(129, 117);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Email";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(129, 157);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 16);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Phone";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(129, 195);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(67, 16);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Password";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(129, 234);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(115, 16);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Confirm Password";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(264, 67);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(213, 22);
			this->tbName->TabIndex = 6;
			// 
			// tbEmail
			// 
			this->tbEmail->Location = System::Drawing::Point(264, 108);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(213, 22);
			this->tbEmail->TabIndex = 7;
			// 
			// tbConfirm
			// 
			this->tbConfirm->Location = System::Drawing::Point(264, 228);
			this->tbConfirm->Name = L"tbConfirm";
			this->tbConfirm->PasswordChar = '*';
			this->tbConfirm->Size = System::Drawing::Size(213, 22);
			this->tbConfirm->TabIndex = 8;
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(264, 189);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(213, 22);
			this->tbPassword->TabIndex = 9;
			// 
			// tbPhone
			// 
			this->tbPhone->Location = System::Drawing::Point(264, 151);
			this->tbPhone->Name = L"tbPhone";
			this->tbPhone->Size = System::Drawing::Size(213, 22);
			this->tbPhone->TabIndex = 10;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(151, 309);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 40);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Register";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RegisterForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(363, 309);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(114, 40);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Login";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &RegisterForm::button2_Click);
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(953, 552);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tbPhone);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbConfirm);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"RegisterForm";
			this->Text = L"RegisterForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		bool _switchToLogin = false;

	public:
		User^ m_user = nullptr;
		bool getSwitchToLogin() {
			return _switchToLogin;
		}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->_switchToLogin = true;
		this->Close();
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ name = tbName->Text;
		String^ email = tbEmail->Text;
		String^ phone = tbPhone->Text;
		String^ password = tbPassword->Text;
		String^ passwordConfirm = tbConfirm->Text;

		if (name->Length == 0 || email->Length == 0 || phone->Length == 0 || password->Length == 0 || passwordConfirm->Length == 0) {
			MessageBox::Show("Enter all fields", "Error", MessageBoxButtons::OK);
			return;
		}

		// TODO: Email validation
		if (String::Compare(password, passwordConfirm) != 0) {
			MessageBox::Show("Passwords do not match", "Error", MessageBoxButtons::OK);
			return;
		}

		try
		{
			String^ connectionString = "Data Source=(localdb)\\MSSqlLocalDB;Initial Catalog=auth;Integrated Security=True";
			SqlConnection dbConnection(connectionString);
			dbConnection.Open();

			String^ putUserQuery = "INSERT INTO users (name, email, phone, password) VALUES" + 
								   "(@name, @email, @phone, @password)";
			SqlCommand query(putUserQuery, % dbConnection);
			query.Parameters->AddWithValue("@name", name);
			query.Parameters->AddWithValue("@email", email);
			query.Parameters->AddWithValue("@phone", phone);
			query.Parameters->AddWithValue("@password", password);

			m_user = gcnew User;
			m_user->m_name = name;
			m_user->m_email = email;
			m_user->m_phone = phone;
			m_user->m_password = password;

			query.ExecuteNonQuery();
			this->Close();
		}
		catch (Exception^ error) 
		{
			MessageBox::Show("Database error", "Error", MessageBoxButtons::OK);
		}
	}
};
}
