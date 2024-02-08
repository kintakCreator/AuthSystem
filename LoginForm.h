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
	/// —водка дл€ LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~LoginForm()
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
	private: System::Windows::Forms::TextBox^ tbEmail;
	private: System::Windows::Forms::TextBox^ tbPassword;
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
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(26, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(452, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to Auth System! Please login";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(50, 143);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 32);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Email";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(50, 207);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(111, 32);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Password";
			// 
			// tbEmail
			// 
			this->tbEmail->Location = System::Drawing::Point(198, 135);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(266, 39);
			this->tbEmail->TabIndex = 3;
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(198, 207);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(266, 39);
			this->tbPassword->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(56, 293);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(216, 41);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(358, 293);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(216, 41);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Register";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &LoginForm::button2_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 32);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(716, 508);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	public: 
		User^ m_user = nullptr;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ email = this->tbEmail->Text;
		String^ password = this->tbPassword->Text;

		// TODO: email validation
		if (email->Length == 0 || password->Length == 0) 
		{
			MessageBox::Show("You need to enter email and password", "Error", MessageBoxButtons::OK);
			return;
		}

		try 
		{
			String^ connectionString = "Data Source=(localdb)\\MSSqlLocalDB;Initial Catalog=auth;Integrated Security=True";
			SqlConnection dbConnection(connectionString);
			dbConnection.Open();

			String^ getUserQuery = "SELECT * FROM users WHERE (email=@email) AND (password=@password)";
			SqlCommand query(getUserQuery, % dbConnection);
			query.Parameters->AddWithValue("@email", email);
			query.Parameters->AddWithValue("@password", password);
			
			SqlDataReader^ result = query.ExecuteReader();
			if (result->Read())
			{
				m_user = gcnew User;
				m_user->m_id = result->GetInt32(0);
				m_user->m_name = result->GetString(1);
				m_user->m_email = result->GetString(2);
				m_user->m_phone = result->GetString(3);
				m_user->m_password = result->GetString(4);

				this->Close();
			}
			else
			{
				MessageBox::Show("Email or password is incorrect", "Error", MessageBoxButtons::OK);
			}
		}
		catch (Exception^ error)
		{
			MessageBox::Show("Database error", "Error", MessageBoxButtons::OK);
		}
	}

	public:
		bool getSwitchToRegister() 
		{
			return _switchToRegister;
		}

	private:
		bool _switchToRegister = false;

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->_switchToRegister = true;
		this->Close();
	}
};
}
