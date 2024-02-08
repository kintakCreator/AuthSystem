#pragma once

#include "LoginForm.h"
#include "RegisterForm.h"
#include "Dashboard.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	User^ user = nullptr;
	while (true) 
	{
		AuthSystem::LoginForm loginForm;
		loginForm.ShowDialog();

		if (loginForm.getSwitchToRegister())
		{
			AuthSystem::RegisterForm registerForm;
			registerForm.ShowDialog();
			
			if (registerForm.getSwitchToLogin())
				continue;

			user = registerForm.m_user;
			break;
		}
		else 
		{
			user = loginForm.m_user; // TODO: encapsulate
			break;
		}
	}

	if (user != nullptr)
	{
		AuthSystem::Dashboard dashboard(user);
		Application::Run(% dashboard);
	}
}