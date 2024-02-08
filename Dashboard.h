#pragma once

#include "User.h"

namespace AuthSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		Dashboard(User^ user)
		{
			InitializeComponent();
			lbUserData->Text = "Welcome, " + user->m_name;
			lbEmail->Text = "Your email: " + user->m_email;
			lbPhone->Text = "Your phone: " + user->m_phone;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lbUserData;
	private: System::Windows::Forms::Label^ lbEmail;
	private: System::Windows::Forms::Label^ lbPhone;
	protected:


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
			this->lbUserData = (gcnew System::Windows::Forms::Label());
			this->lbEmail = (gcnew System::Windows::Forms::Label());
			this->lbPhone = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(299, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Dashboard";
			this->label1->Click += gcnew System::EventHandler(this, &Dashboard::label1_Click);
			// 
			// lbUserData
			// 
			this->lbUserData->AutoSize = true;
			this->lbUserData->Location = System::Drawing::Point(12, 94);
			this->lbUserData->Name = L"lbUserData";
			this->lbUserData->Size = System::Drawing::Size(86, 16);
			this->lbUserData->TabIndex = 1;
			this->lbUserData->Text = L"%userData%";
			// 
			// lbEmail
			// 
			this->lbEmail->AutoSize = true;
			this->lbEmail->Location = System::Drawing::Point(12, 138);
			this->lbEmail->Name = L"lbEmail";
			this->lbEmail->Size = System::Drawing::Size(64, 16);
			this->lbEmail->TabIndex = 2;
			this->lbEmail->Text = L"%email%";
			// 
			// lbPhone
			// 
			this->lbPhone->AutoSize = true;
			this->lbPhone->Location = System::Drawing::Point(12, 188);
			this->lbPhone->Name = L"lbPhone";
			this->lbPhone->Size = System::Drawing::Size(69, 16);
			this->lbPhone->TabIndex = 3;
			this->lbPhone->Text = L"%phone%";
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(773, 569);
			this->Controls->Add(this->lbPhone);
			this->Controls->Add(this->lbEmail);
			this->Controls->Add(this->lbUserData);
			this->Controls->Add(this->label1);
			this->Name = L"Dashboard";
			this->Text = L"Dashboard";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
