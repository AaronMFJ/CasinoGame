#pragma once


namespace CasinoGame

{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CasinoForm
	/// </summary>
	public ref class CasinoForm : public System::Windows::Forms::Form
	{
	public:
		CasinoForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CasinoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  nameBox;
	protected:
	private: System::Windows::Forms::Button^  submitButton;


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
			this->submitButton = (gcnew System::Windows::Forms::Button());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// submitButton
			// 
			this->submitButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->submitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->submitButton->Location = System::Drawing::Point(161, 289);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(185, 43);
			this->submitButton->TabIndex = 0;
			this->submitButton->Text = L"Submit";
			this->submitButton->UseVisualStyleBackColor = false;
			// 
			// nameBox
			// 
			this->nameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameBox->Location = System::Drawing::Point(161, 138);
			this->nameBox->Multiline = true;
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(185, 36);
			this->nameBox->TabIndex = 1;
			// 
			// CasinoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(539, 392);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->submitButton);
			this->Name = L"CasinoForm";
			this->Text = L"CasinoForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
	}
	};
}
