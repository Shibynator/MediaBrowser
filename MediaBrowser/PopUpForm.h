#pragma once

namespace MediaBrowser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für PopUpForm
	/// </summary>
	public ref class PopUpForm : public System::Windows::Forms::Form
	{
	public:
		PopUpForm(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}
	
		// Überladener Konstruktor
		PopUpForm(String ^ windowTitle, String ^ errorTitle, String ^ errorText)
		{
			InitializeComponent();

			// set textes
			Text = windowTitle;
			labelTitle->Text = errorTitle;
			labelError->Text = errorText;
			Show();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~PopUpForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelTitle;
	protected:
	private: System::Windows::Forms::Label^  labelError;
	private: System::Windows::Forms::Button^  buttonOK;
	public:


	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelError = (gcnew System::Windows::Forms::Label());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(32, 39);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(46, 26);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"title";
			// 
			// labelError
			// 
			this->labelError->AutoSize = true;
			this->labelError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelError->Location = System::Drawing::Point(32, 88);
			this->labelError->Name = L"labelError";
			this->labelError->Size = System::Drawing::Size(57, 26);
			this->labelError->TabIndex = 1;
			this->labelError->Text = L"error";
			this->labelError->Click += gcnew System::EventHandler(this, &PopUpForm::labelError_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonOK->Location = System::Drawing::Point(373, 172);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(137, 45);
			this->buttonOK->TabIndex = 2;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &PopUpForm::buttonOK_Click);
			// 
			// PopUpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(874, 229);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->labelError);
			this->Controls->Add(this->labelTitle);
			this->MaximumSize = System::Drawing::Size(900, 300);
			this->MinimumSize = System::Drawing::Size(900, 300);
			this->Name = L"PopUpForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PopUpForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void labelError_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}
