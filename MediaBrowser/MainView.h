#pragma once

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <id3/tag.h>
#include <id3/misc_support.h>

#include "MusicCatalog.h"
#include "PictureCatalog.h"
#include "MovieCatalog.h"

#include "MusicFile.h"
#include "PictureFile.h"
#include "MovieFile.h"

#include "MediaInfoDLL.h"

#include "PopUpForm.h"

namespace MediaBrowser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;
	//using namespace MediaInfoDLL;		// problem: zweite deklaration von String

	/// <summary>
	/// Zusammenfassung für MainView
	/// </summary>
	public ref class MainView : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::TabControl^  tabControlCatalog;
	private: System::Windows::Forms::TabPage^  tabPageMusic;

	private: System::Windows::Forms::TabPage^  tabPagePicture;
	private: System::Windows::Forms::TabPage^  tabPageMovie;

	private: System::Windows::Forms::DataGridView^  dataGridViewPicture;
	private: System::Windows::Forms::DataGridView^  dataGridViewMovie;
	private: System::Windows::Forms::DataGridView^  dataGridViewMusic;

	private:	MusicCatalog  ^ musicCatalog;
	private:	PictureCatalog ^ pictureCatalog;
	private: System::Windows::Forms::TextBox^  textBoxSearch;
	private: System::Windows::Forms::Label^  labelSearch;
	private: System::Windows::Forms::ToolStripMenuItem^  katalogeSpeichernToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  katalogeLadenToolStripMenuItem;







	private:	MovieCatalog ^ movieCatalog;

	public:
		MainView(void)
		{
			InitializeComponent();

			musicCatalog = gcnew MusicCatalog("musicCatalog.xml", "musicSchema.xml");
			pictureCatalog = gcnew PictureCatalog("pictureCatalog.xml", "pictureSchema.xml");
			movieCatalog = gcnew MovieCatalog("movieCatalog.xml", "movieSchema.xml");

			dataGridViewMusic->DataSource = musicCatalog;
			dataGridViewPicture->DataSource = pictureCatalog;
			dataGridViewMovie->DataSource = movieCatalog;


			dataGridViewMusic->AllowUserToOrderColumns = true;
			dataGridViewPicture->AllowUserToOrderColumns = true;
			dataGridViewMovie->AllowUserToOrderColumns = true;
			//TODO: Konstruktorcode hier hinzufügen.

		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MainView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  dateiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  verzeichnissImportierenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  beendenToolStripMenuItem;

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->dateiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->verzeichnissImportierenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->katalogeSpeichernToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->katalogeLadenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->beendenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControlCatalog = (gcnew System::Windows::Forms::TabControl());
			this->tabPageMusic = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewMusic = (gcnew System::Windows::Forms::DataGridView());
			this->tabPagePicture = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewPicture = (gcnew System::Windows::Forms::DataGridView());
			this->tabPageMovie = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewMovie = (gcnew System::Windows::Forms::DataGridView());
			this->textBoxSearch = (gcnew System::Windows::Forms::TextBox());
			this->labelSearch = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->tabControlCatalog->SuspendLayout();
			this->tabPageMusic->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMusic))->BeginInit();
			this->tabPagePicture->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPicture))->BeginInit();
			this->tabPageMovie->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMovie))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::MidnightBlue;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->dateiToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1894, 40);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// dateiToolStripMenuItem
			// 
			this->dateiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->verzeichnissImportierenToolStripMenuItem,
					this->katalogeSpeichernToolStripMenuItem, this->katalogeLadenToolStripMenuItem, this->beendenToolStripMenuItem
			});
			this->dateiToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->dateiToolStripMenuItem->Name = L"dateiToolStripMenuItem";
			this->dateiToolStripMenuItem->Size = System::Drawing::Size(83, 36);
			this->dateiToolStripMenuItem->Text = L"Datei";
			// 
			// verzeichnissImportierenToolStripMenuItem
			// 
			this->verzeichnissImportierenToolStripMenuItem->BackColor = System::Drawing::Color::MidnightBlue;
			this->verzeichnissImportierenToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->verzeichnissImportierenToolStripMenuItem->Name = L"verzeichnissImportierenToolStripMenuItem";
			this->verzeichnissImportierenToolStripMenuItem->Size = System::Drawing::Size(358, 36);
			this->verzeichnissImportierenToolStripMenuItem->Text = L"Verzeichnis importieren...";
			this->verzeichnissImportierenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainView::verzeichnissImportierenToolStripMenuItem_Click);
			// 
			// katalogeSpeichernToolStripMenuItem
			// 
			this->katalogeSpeichernToolStripMenuItem->BackColor = System::Drawing::Color::MidnightBlue;
			this->katalogeSpeichernToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->katalogeSpeichernToolStripMenuItem->Name = L"katalogeSpeichernToolStripMenuItem";
			this->katalogeSpeichernToolStripMenuItem->Size = System::Drawing::Size(358, 36);
			this->katalogeSpeichernToolStripMenuItem->Text = L"Speichern";
			this->katalogeSpeichernToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainView::katalogeSpeichernToolStripMenuItem_Click);
			// 
			// katalogeLadenToolStripMenuItem
			// 
			this->katalogeLadenToolStripMenuItem->BackColor = System::Drawing::Color::MidnightBlue;
			this->katalogeLadenToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->katalogeLadenToolStripMenuItem->Name = L"katalogeLadenToolStripMenuItem";
			this->katalogeLadenToolStripMenuItem->Size = System::Drawing::Size(358, 36);
			this->katalogeLadenToolStripMenuItem->Text = L"Laden";
			this->katalogeLadenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainView::katalogeLadenToolStripMenuItem_Click);
			// 
			// beendenToolStripMenuItem
			// 
			this->beendenToolStripMenuItem->BackColor = System::Drawing::Color::MidnightBlue;
			this->beendenToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->beendenToolStripMenuItem->Name = L"beendenToolStripMenuItem";
			this->beendenToolStripMenuItem->Size = System::Drawing::Size(358, 36);
			this->beendenToolStripMenuItem->Text = L"Beenden";
			this->beendenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainView::beendenToolStripMenuItem_Click);
			// 
			// tabControlCatalog
			// 
			this->tabControlCatalog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControlCatalog->Controls->Add(this->tabPageMusic);
			this->tabControlCatalog->Controls->Add(this->tabPagePicture);
			this->tabControlCatalog->Controls->Add(this->tabPageMovie);
			this->tabControlCatalog->Location = System::Drawing::Point(17, 103);
			this->tabControlCatalog->Margin = System::Windows::Forms::Padding(4);
			this->tabControlCatalog->Name = L"tabControlCatalog";
			this->tabControlCatalog->SelectedIndex = 0;
			this->tabControlCatalog->Size = System::Drawing::Size(1861, 890);
			this->tabControlCatalog->TabIndex = 1;
			// 
			// tabPageMusic
			// 
			this->tabPageMusic->BackColor = System::Drawing::Color::Transparent;
			this->tabPageMusic->Controls->Add(this->dataGridViewMusic);
			this->tabPageMusic->ForeColor = System::Drawing::SystemColors::ControlText;
			this->tabPageMusic->Location = System::Drawing::Point(4, 34);
			this->tabPageMusic->Margin = System::Windows::Forms::Padding(4);
			this->tabPageMusic->Name = L"tabPageMusic";
			this->tabPageMusic->Padding = System::Windows::Forms::Padding(4);
			this->tabPageMusic->Size = System::Drawing::Size(1853, 852);
			this->tabPageMusic->TabIndex = 0;
			this->tabPageMusic->Text = L"Musik";
			// 
			// dataGridViewMusic
			// 
			this->dataGridViewMusic->AllowUserToAddRows = false;
			this->dataGridViewMusic->AllowUserToDeleteRows = false;
			this->dataGridViewMusic->AllowUserToResizeRows = false;
			this->dataGridViewMusic->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewMusic->BackgroundColor = System::Drawing::Color::MidnightBlue;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewMusic->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewMusic->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::MidnightBlue;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::DodgerBlue;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewMusic->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridViewMusic->GridColor = System::Drawing::Color::DodgerBlue;
			this->dataGridViewMusic->Location = System::Drawing::Point(0, 0);
			this->dataGridViewMusic->Margin = System::Windows::Forms::Padding(0);
			this->dataGridViewMusic->MultiSelect = false;
			this->dataGridViewMusic->Name = L"dataGridViewMusic";
			this->dataGridViewMusic->RowHeadersWidth = 20;
			this->dataGridViewMusic->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewMusic->Size = System::Drawing::Size(1857, 852);
			this->dataGridViewMusic->TabIndex = 0;
			this->dataGridViewMusic->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainView::dataGridViewMusic_CellDoubleClick);
			this->dataGridViewMusic->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainView::dataGridViewMusic_CellValueChanged);
			this->dataGridViewMusic->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainView::dataGridViewMusic_KeyDown);
			// 
			// tabPagePicture
			// 
			this->tabPagePicture->BackColor = System::Drawing::Color::Transparent;
			this->tabPagePicture->Controls->Add(this->dataGridViewPicture);
			this->tabPagePicture->ForeColor = System::Drawing::SystemColors::ControlText;
			this->tabPagePicture->Location = System::Drawing::Point(4, 34);
			this->tabPagePicture->Margin = System::Windows::Forms::Padding(4);
			this->tabPagePicture->Name = L"tabPagePicture";
			this->tabPagePicture->Padding = System::Windows::Forms::Padding(4);
			this->tabPagePicture->Size = System::Drawing::Size(1853, 852);
			this->tabPagePicture->TabIndex = 1;
			this->tabPagePicture->Text = L"Bilder";
			// 
			// dataGridViewPicture
			// 
			this->dataGridViewPicture->AllowUserToAddRows = false;
			this->dataGridViewPicture->AllowUserToDeleteRows = false;
			this->dataGridViewPicture->AllowUserToResizeRows = false;
			this->dataGridViewPicture->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewPicture->BackgroundColor = System::Drawing::Color::MidnightBlue;
			this->dataGridViewPicture->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::MidnightBlue;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::DodgerBlue;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewPicture->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridViewPicture->GridColor = System::Drawing::Color::DodgerBlue;
			this->dataGridViewPicture->Location = System::Drawing::Point(0, 0);
			this->dataGridViewPicture->Margin = System::Windows::Forms::Padding(0);
			this->dataGridViewPicture->MultiSelect = false;
			this->dataGridViewPicture->Name = L"dataGridViewPicture";
			this->dataGridViewPicture->RowHeadersWidth = 20;
			this->dataGridViewPicture->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewPicture->Size = System::Drawing::Size(1857, 852);
			this->dataGridViewPicture->TabIndex = 1;
			this->dataGridViewPicture->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainView::dataGridViewPicture_CellDoubleClick);
			this->dataGridViewPicture->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainView::dataGridViewPicture_KeyDown);
			// 
			// tabPageMovie
			// 
			this->tabPageMovie->BackColor = System::Drawing::Color::Transparent;
			this->tabPageMovie->Controls->Add(this->dataGridViewMovie);
			this->tabPageMovie->ForeColor = System::Drawing::SystemColors::ControlText;
			this->tabPageMovie->Location = System::Drawing::Point(4, 34);
			this->tabPageMovie->Margin = System::Windows::Forms::Padding(4);
			this->tabPageMovie->Name = L"tabPageMovie";
			this->tabPageMovie->Size = System::Drawing::Size(1853, 852);
			this->tabPageMovie->TabIndex = 2;
			this->tabPageMovie->Text = L"Videos";
			// 
			// dataGridViewMovie
			// 
			this->dataGridViewMovie->AllowUserToAddRows = false;
			this->dataGridViewMovie->AllowUserToDeleteRows = false;
			this->dataGridViewMovie->AllowUserToResizeRows = false;
			this->dataGridViewMovie->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewMovie->BackgroundColor = System::Drawing::Color::MidnightBlue;
			this->dataGridViewMovie->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::MidnightBlue;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::DodgerBlue;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewMovie->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridViewMovie->GridColor = System::Drawing::Color::DodgerBlue;
			this->dataGridViewMovie->Location = System::Drawing::Point(0, 0);
			this->dataGridViewMovie->Margin = System::Windows::Forms::Padding(0);
			this->dataGridViewMovie->MultiSelect = false;
			this->dataGridViewMovie->Name = L"dataGridViewMovie";
			this->dataGridViewMovie->RowHeadersWidth = 20;
			this->dataGridViewMovie->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewMovie->Size = System::Drawing::Size(1857, 852);
			this->dataGridViewMovie->TabIndex = 1;
			this->dataGridViewMovie->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainView::dataGridViewMovie_CellDoubleClick);
			this->dataGridViewMovie->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainView::dataGridViewMovie_KeyDown);
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->BackColor = System::Drawing::Color::MidnightBlue;
			this->textBoxSearch->ForeColor = System::Drawing::Color::White;
			this->textBoxSearch->Location = System::Drawing::Point(117, 62);
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(391, 31);
			this->textBoxSearch->TabIndex = 2;
			this->textBoxSearch->TextChanged += gcnew System::EventHandler(this, &MainView::textBox1_TextChanged);
			// 
			// labelSearch
			// 
			this->labelSearch->AutoSize = true;
			this->labelSearch->ForeColor = System::Drawing::Color::White;
			this->labelSearch->Location = System::Drawing::Point(20, 65);
			this->labelSearch->Name = L"labelSearch";
			this->labelSearch->Size = System::Drawing::Size(91, 25);
			this->labelSearch->TabIndex = 3;
			this->labelSearch->Text = L"Suchen:";
			// 
			// MainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(1894, 1009);
			this->Controls->Add(this->labelSearch);
			this->Controls->Add(this->textBoxSearch);
			this->Controls->Add(this->tabControlCatalog);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(1024, 768);
			this->Name = L"MainView";
			this->Text = L"MediaBrowser";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControlCatalog->ResumeLayout(false);
			this->tabPageMusic->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMusic))->EndInit();
			this->tabPagePicture->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPicture))->EndInit();
			this->tabPageMovie->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMovie))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void beendenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void verzeichnissImportierenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		FolderBrowserDialog ^ folderDialog = gcnew FolderBrowserDialog();
		if (folderDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			musicCatalog->import(folderDialog->SelectedPath);
			movieCatalog->import(folderDialog->SelectedPath);
			pictureCatalog->import(folderDialog->SelectedPath);
		}
		else
		{
			//	folderPath = "undef";
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if(tabControlCatalog->SelectedTab == tabControlCatalog->TabPages["tabPageMusic"])
		{
			this->musicCatalog->search(this->textBoxSearch->Text);
		}
		else if (tabControlCatalog->SelectedTab == tabControlCatalog->TabPages["tabPagePicture"])
		{
			this->pictureCatalog->search(this->textBoxSearch->Text);
		}
		else if (tabControlCatalog->SelectedTab == tabControlCatalog->TabPages["tabPageMovie"])
		{
			this->movieCatalog->search(this->textBoxSearch->Text);
		}
	}
	private: System::Void dataGridViewMusic_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		musicCatalog->getFile(this->dataGridViewMusic->CurrentRow)->play();
	}
	private: System::Void dataGridViewPicture_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		pictureCatalog->getFile(this->dataGridViewPicture->CurrentRow)->play();
	}
	private: System::Void dataGridViewMovie_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		movieCatalog->getFile (this->dataGridViewMovie->CurrentRow)->play();
	}
	private: System::Void dataGridViewMusic_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Delete)
		{
			musicCatalog->remove(this->dataGridViewMusic->CurrentRow);
			e->Handled = true;
		}
	}
	private: System::Void dataGridViewPicture_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Delete)
		{
			pictureCatalog->remove(this->dataGridViewPicture->CurrentRow);
			e->Handled = true;
		}
	}
	private: System::Void dataGridViewMovie_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Delete)
		{
			movieCatalog->remove(this->dataGridViewMovie->CurrentRow);
			e->Handled = true;
		}
	}
	private: System::Void dataGridViewMusic_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		musicCatalog->getFile(this->dataGridViewMusic->CurrentRow)->edit();
	}
	private: System::Void katalogeLadenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		musicCatalog->load();
		pictureCatalog->load();
		movieCatalog->load();
	}
	private: System::Void katalogeSpeichernToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		musicCatalog->save();
		pictureCatalog->save();
		movieCatalog->save();
	}
};
}
