#pragma once
#include "Client.h"
#include <msclr/marshal_cppstd.h>

#pragma warning(disable: 4996)

client test;

namespace CHAT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// —водка дл€ Chat
	/// </summary>
	public ref class Chat : public System::Windows::Forms::Form
	{
	public:
		Chat(void)
		{
			InitializeComponent();
			Send->Enabled = false;
			cht->Enabled = false;
			INPUT->Enabled = false;
			
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Chat()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ IP;
	protected:

	private: System::Windows::Forms::Label^ Autor;
	private: System::Windows::Forms::TextBox^ NameIn;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ cht;

	private: System::Windows::Forms::Label^ UsersOnline;
	private: System::Windows::Forms::TextBox^ INPUT;
	private: System::Windows::Forms::Button^ Send;
	private: System::Windows::Forms::TextBox^ password;
	private: System::Windows::Forms::TextBox^ Port;
	private: System::Windows::Forms::Label^ iplab;
	private: System::Windows::Forms::Label^ portlab;
	private: System::Windows::Forms::Label^ uncorr;

	protected:


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Chat::typeid));
			this->IP = (gcnew System::Windows::Forms::TextBox());
			this->Autor = (gcnew System::Windows::Forms::Label());
			this->NameIn = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->cht = (gcnew System::Windows::Forms::RichTextBox());
			this->UsersOnline = (gcnew System::Windows::Forms::Label());
			this->INPUT = (gcnew System::Windows::Forms::TextBox());
			this->Send = (gcnew System::Windows::Forms::Button());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->Port = (gcnew System::Windows::Forms::TextBox());
			this->iplab = (gcnew System::Windows::Forms::Label());
			this->portlab = (gcnew System::Windows::Forms::Label());
			this->uncorr = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// IP
			// 
			this->IP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->IP->Location = System::Drawing::Point(36, 303);
			this->IP->Name = L"IP";
			this->IP->Size = System::Drawing::Size(140, 27);
			this->IP->TabIndex = 0;
			this->IP->Text = L"127.0.0.1";
			this->IP->Click += gcnew System::EventHandler(this, &Chat::IP_Click);
			this->IP->TextChanged += gcnew System::EventHandler(this, &Chat::IP_TextChanged);
			// 
			// Autor
			// 
			this->Autor->AutoSize = true;
			this->Autor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Autor->Location = System::Drawing::Point(33, 43);
			this->Autor->Name = L"Autor";
			this->Autor->Size = System::Drawing::Size(131, 20);
			this->Autor->TabIndex = 1;
			this->Autor->Text = L"јвторизаци€";
			this->Autor->Click += gcnew System::EventHandler(this, &Chat::Autor_Click);
			// 
			// NameIn
			// 
			this->NameIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NameIn->Location = System::Drawing::Point(36, 75);
			this->NameIn->Name = L"NameIn";
			this->NameIn->Size = System::Drawing::Size(140, 27);
			this->NameIn->TabIndex = 2;
			this->NameIn->Text = L"Name";
			this->NameIn->Click += gcnew System::EventHandler(this, &Chat::NameIn_Click);
			this->NameIn->TextChanged += gcnew System::EventHandler(this, &Chat::NameIn_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(47, 159);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 41);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Connect";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Chat::button1_Click);
			// 
			// cht
			// 
			this->cht->BackColor = System::Drawing::Color::White;
			this->cht->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->cht->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cht->ForeColor = System::Drawing::Color::Black;
			this->cht->Location = System::Drawing::Point(215, 40);
			this->cht->Name = L"cht";
			this->cht->ReadOnly = true;
			this->cht->Size = System::Drawing::Size(307, 339);
			this->cht->TabIndex = 4;
			this->cht->Text = L"";
			this->cht->TextChanged += gcnew System::EventHandler(this, &Chat::cht_TextChanged);
			// 
			// UsersOnline
			// 
			this->UsersOnline->AutoSize = true;
			this->UsersOnline->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->UsersOnline->Location = System::Drawing::Point(220, 15);
			this->UsersOnline->Name = L"UsersOnline";
			this->UsersOnline->Size = System::Drawing::Size(126, 22);
			this->UsersOnline->TabIndex = 5;
			this->UsersOnline->Text = L"Users Online";
			this->UsersOnline->Click += gcnew System::EventHandler(this, &Chat::UsersOnline_Click);
			// 
			// INPUT
			// 
			this->INPUT->BackColor = System::Drawing::Color::White;
			this->INPUT->Location = System::Drawing::Point(215, 398);
			this->INPUT->Name = L"INPUT";
			this->INPUT->Size = System::Drawing::Size(233, 22);
			this->INPUT->TabIndex = 6;
			this->INPUT->TextChanged += gcnew System::EventHandler(this, &Chat::INPUT_TextChanged);
			// 
			// Send
			// 
			this->Send->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Send->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Send->FlatAppearance->BorderColor = System::Drawing::SystemColors::AppWorkspace;
			this->Send->FlatAppearance->BorderSize = 0;
			this->Send->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Send->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Send.Image")));
			this->Send->Location = System::Drawing::Point(443, 385);
			this->Send->Name = L"Send";
			this->Send->Size = System::Drawing::Size(68, 48);
			this->Send->TabIndex = 7;
			this->Send->UseVisualStyleBackColor = true;
			this->Send->Click += gcnew System::EventHandler(this, &Chat::Send_Click);
			this->Send->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Chat::Send_Paint);
			this->Send->Enter += gcnew System::EventHandler(this, &Chat::Send_Enter);
			// 
			// password
			// 
			this->password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->password->Location = System::Drawing::Point(36, 114);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(140, 27);
			this->password->TabIndex = 8;
			this->password->Text = L"password";
			this->password->Click += gcnew System::EventHandler(this, &Chat::password_Click);
			this->password->TextChanged += gcnew System::EventHandler(this, &Chat::password_TextChanged);
			// 
			// Port
			// 
			this->Port->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Port->Location = System::Drawing::Point(36, 357);
			this->Port->Name = L"Port";
			this->Port->Size = System::Drawing::Size(100, 27);
			this->Port->TabIndex = 9;
			this->Port->Text = L"12345";
			this->Port->Click += gcnew System::EventHandler(this, &Chat::Port_Click);
			this->Port->TextChanged += gcnew System::EventHandler(this, &Chat::Port_TextChanged);
			// 
			// iplab
			// 
			this->iplab->AutoSize = true;
			this->iplab->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->iplab->Location = System::Drawing::Point(33, 278);
			this->iplab->Name = L"iplab";
			this->iplab->Size = System::Drawing::Size(28, 22);
			this->iplab->TabIndex = 10;
			this->iplab->Text = L"IP";
			this->iplab->Click += gcnew System::EventHandler(this, &Chat::iplab_Click);
			// 
			// portlab
			// 
			this->portlab->AutoSize = true;
			this->portlab->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->portlab->Location = System::Drawing::Point(33, 332);
			this->portlab->Name = L"portlab";
			this->portlab->Size = System::Drawing::Size(45, 22);
			this->portlab->TabIndex = 11;
			this->portlab->Text = L"port";
			this->portlab->Click += gcnew System::EventHandler(this, &Chat::portlab_Click);
			// 
			// uncorr
			// 
			this->uncorr->AutoSize = true;
			this->uncorr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->uncorr->Location = System::Drawing::Point(42, 224);
			this->uncorr->Name = L"uncorr";
			this->uncorr->Size = System::Drawing::Size(0, 20);
			this->uncorr->TabIndex = 12;
			// 
			// Chat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(549, 484);
			this->Controls->Add(this->uncorr);
			this->Controls->Add(this->portlab);
			this->Controls->Add(this->iplab);
			this->Controls->Add(this->Port);
			this->Controls->Add(this->password);
			this->Controls->Add(this->Send);
			this->Controls->Add(this->INPUT);
			this->Controls->Add(this->UsersOnline);
			this->Controls->Add(this->cht);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->NameIn);
			this->Controls->Add(this->Autor);
			this->Controls->Add(this->IP);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Chat";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Chat";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void IP_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void NameIn_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Autor_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (button1->Text == "Connect") {
			this->uncorr->Text = "";
			String^ name = NameIn->Text;
			String^ Ip = IP->Text;
			String^ pass = password->Text;
			String^ port = Port->Text;
			int PORT = Convert::ToInt32(port);


			std::string ip;
			std::string log;
			std::string passw;


			to_str(log, name);
			to_str(passw, pass);
			to_str(ip, Ip);


			test.set_ip(ip);
			test.set_port(PORT);
			test.set_login(log);
			test.set_password(passw);
			

			test.bindSocket();
			try {
				test.connection();
			}
			catch(const std::logic_error& ex){
				this->uncorr->Text = "Can't connect";
				return;
			}
			
			if (test.signUP()) {
				Send->Enabled = true;
				cht->Enabled = true;
				INPUT->Enabled = true;
				NameIn->Enabled = false;
				IP->Enabled = false;
				password->Enabled = false;
				Port->Enabled = false;
				button1->Text = "Disconnect";
			}
			else {
				uncorr->Text = "Uncorrect";
				return;
			}

			Thread^ getThread = gcnew Thread(gcnew ThreadStart(this, &Chat::get));
			getThread->Start();
		}
		else if (button1->Text =="Disconnect") {
			Send->Enabled = false;
			cht->Enabled = false;
			INPUT->Enabled = false;
			INPUT->Clear();
			NameIn->Enabled = true;
			IP->Enabled = true;
			password->Enabled = true;
			Port->Enabled = true;
			button1->Text = "Connect";
			this->UsersOnline->Text = "Users Online:";
			test.disconnect();
			

			

			
		}

	}
	private: System::Void IP_Click(System::Object^ sender, System::EventArgs^ e) {
		if (IP->Text == "IP") {
			IP->Text = "";
		}
	}
	private: System::Void NameIn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (NameIn->Text == "Name") {
			NameIn->Text = "";
		}
	}

	private: System::Void to_str(std::string& str, String^ text) {
		msclr::interop::marshal_context contex;
		str = contex.marshal_as<std::string>(text);
	}
	

private: System::Void cht_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	cht->ReadOnly = true;
	cht->HideSelection = true;
}
private: System::Void INPUT_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void UsersOnline_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Send_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ text = INPUT->Text;
	INPUT->Text = "";
	std::string msg;
	to_str(msg, text);
	test.SendData(msg);
	
}
private: System::Void password_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Port_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Port_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Port->Text == "Port") {
		Port->Text = "";
	}
}
private: System::Void password_Click(System::Object^ sender, System::EventArgs^ e) {
	if (password->Text == "password") {
		password->Text = "";
	}
}
private: System::Void iplab_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::String^ to_STR(std::string text) {
	msclr::interop::marshal_context cont;
	return cont.marshal_as<String^>(text);
}
private: System::Void portlab_Click(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void get() {
		try {
			while (this->INPUT->Enabled == true) {
				std::string who = test.Recieve();
				if (INPUT->Enabled == false) { break; }
				String^ wh = to_STR(who);
				if (wh->StartsWith("&dsa9dwaldwoaiddwahgdgy872coac")) {
					this->UsersOnline->Text = "";
					String^ num = "";
					for (int i = 30; i < wh->Length; i++) {
						num += wh[i];
					}
					this->UsersOnline->Text = "Users online : " + num;
				}
				else {
					std::string msg = test.Recieve();
					String^ message = to_STR(msg);
					cht->AppendText("from " + wh + " : " + message + "\n");
				}
			}
		}
		catch (const std::logic_error& ex) {
			return;
		}
		
	}
private: System::Void Send_Enter(System::Object^ sender, System::EventArgs^ e) {
	String^ text = INPUT->Text;
	INPUT->Text = "";
	std::string msg;
	to_str(msg, text);
	test.SendData(msg);
}
private: System::Void Send_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

}
};
}
