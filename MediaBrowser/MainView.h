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




	private:	MovieCatalog ^ movieCatalog;

	public:
		MainView(void)
		{
			InitializeComponent();

			musicCatalog = gcnew MusicCatalog();
			pictureCatalog = gcnew PictureCatalog();
			movieCatalog = gcnew MovieCatalog();

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->dateiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->verzeichnissImportierenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->dateiToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(2322, 40);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// dateiToolStripMenuItem
			// 
			this->dateiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->verzeichnissImportierenToolStripMenuItem,
					this->beendenToolStripMenuItem
			});
			this->dateiToolStripMenuItem->Name = L"dateiToolStripMenuItem";
			this->dateiToolStripMenuItem->Size = System::Drawing::Size(83, 36);
			this->dateiToolStripMenuItem->Text = L"Datei";
			// 
			// verzeichnissImportierenToolStripMenuItem
			// 
			this->verzeichnissImportierenToolStripMenuItem->Name = L"verzeichnissImportierenToolStripMenuItem";
			this->verzeichnissImportierenToolStripMenuItem->Size = System::Drawing::Size(368, 36);
			this->verzeichnissImportierenToolStripMenuItem->Text = L"Verzeichniss importieren...";
			this->verzeichnissImportierenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainView::verzeichnissImportierenToolStripMenuItem_Click);
			// 
			// beendenToolStripMenuItem
			// 
			this->beendenToolStripMenuItem->Name = L"beendenToolStripMenuItem";
			this->beendenToolStripMenuItem->Size = System::Drawing::Size(368, 36);
			this->beendenToolStripMenuItem->Text = L"Beenden";
			this->beendenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainView::beendenToolStripMenuItem_Click);
			// 
			// tabControlCatalog
			// 
			this->tabControlCatalog->Controls->Add(this->tabPageMusic);
			this->tabControlCatalog->Controls->Add(this->tabPagePicture);
			this->tabControlCatalog->Controls->Add(this->tabPageMovie);
			this->tabControlCatalog->Location = System::Drawing::Point(17, 103);
			this->tabControlCatalog->Margin = System::Windows::Forms::Padding(4);
			this->tabControlCatalog->Name = L"tabControlCatalog";
			this->tabControlCatalog->SelectedIndex = 0;
			this->tabControlCatalog->Size = System::Drawing::Size(1476, 760);
			this->tabControlCatalog->TabIndex = 1;
			// 
			// tabPageMusic
			// 
			this->tabPageMusic->Controls->Add(this->dataGridViewMusic);
			this->tabPageMusic->Location = System::Drawing::Point(4, 34);
			this->tabPageMusic->Margin = System::Windows::Forms::Padding(4);
			this->tabPageMusic->Name = L"tabPageMusic";
			this->tabPageMusic->Padding = System::Windows::Forms::Padding(4);
			this->tabPageMusic->Size = System::Drawing::Size(1468, 722);
			this->tabPageMusic->TabIndex = 0;
			this->tabPageMusic->Text = L"Musik";
			this->tabPageMusic->UseVisualStyleBackColor = true;
			// 
			// dataGridViewMusic
			// 
			this->dataGridViewMusic->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewMusic->Location = System::Drawing::Point(0, 0);
			this->dataGridViewMusic->Margin = System::Windows::Forms::Padding(6);
			this->dataGridViewMusic->Name = L"dataGridViewMusic";
			this->dataGridViewMusic->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewMusic->Size = System::Drawing::Size(1424, 710);
			this->dataGridViewMusic->TabIndex = 0;
			this->dataGridViewMusic->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainView::dataGridViewMusic_CellDoubleClick);
			// 
			// tabPagePicture
			// 
			this->tabPagePicture->Controls->Add(this->dataGridViewPicture);
			this->tabPagePicture->Location = System::Drawing::Point(4, 34);
			this->tabPagePicture->Margin = System::Windows::Forms::Padding(4);
			this->tabPagePicture->Name = L"tabPagePicture";
			this->tabPagePicture->Padding = System::Windows::Forms::Padding(4);
			this->tabPagePicture->Size = System::Drawing::Size(1468, 722);
			this->tabPagePicture->TabIndex = 1;
			this->tabPagePicture->Text = L"Bilder";
			this->tabPagePicture->UseVisualStyleBackColor = true;
			// 
			// dataGridViewPicture
			// 
			this->dataGridViewPicture->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewPicture->Location = System::Drawing::Point(4, 4);
			this->dataGridViewPicture->Margin = System::Windows::Forms::Padding(4);
			this->dataGridViewPicture->Name = L"dataGridViewPicture";
			this->dataGridViewPicture->RowTemplate->Height = 33;
			this->dataGridViewPicture->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewPicture->Size = System::Drawing::Size(2184, 713);
			this->dataGridViewPicture->TabIndex = 1;
			this->dataGridViewPicture->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainView::dataGridViewPicture_CellDoubleClick);
			// 
			// tabPageMovie
			// 
			this->tabPageMovie->Controls->Add(this->dataGridViewMovie);
			this->tabPageMovie->Location = System::Drawing::Point(4, 34);
			this->tabPageMovie->Margin = System::Windows::Forms::Padding(4);
			this->tabPageMovie->Name = L"tabPageMovie";
			this->tabPageMovie->Size = System::Drawing::Size(1468, 722);
			this->tabPageMovie->TabIndex = 2;
			this->tabPageMovie->Text = L"Videos";
			this->tabPageMovie->UseVisualStyleBackColor = true;
			// 
			// dataGridViewMovie
			// 
			this->dataGridViewMovie->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewMovie->Location = System::Drawing::Point(4, 4);
			this->dataGridViewMovie->Margin = System::Windows::Forms::Padding(4);
			this->dataGridViewMovie->Name = L"dataGridViewMovie";
			this->dataGridViewMovie->RowTemplate->Height = 33;
			this->dataGridViewMovie->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewMovie->Size = System::Drawing::Size(2188, 715);
			this->dataGridViewMovie->TabIndex = 1;
			this->dataGridViewMovie->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainView::dataGridViewMovie_CellDoubleClick);
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->Location = System::Drawing::Point(117, 62);
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(1085, 31);
			this->textBoxSearch->TabIndex = 2;
			this->textBoxSearch->TextChanged += gcnew System::EventHandler(this, &MainView::textBox1_TextChanged);
			// 
			// labelSearch
			// 
			this->labelSearch->AutoSize = true;
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
			this->ClientSize = System::Drawing::Size(2322, 914);
			this->Controls->Add(this->labelSearch);
			this->Controls->Add(this->textBoxSearch);
			this->Controls->Add(this->tabControlCatalog);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainView";
			this->Text = L"MainView";
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

		//	DataRow ^ drow = safe_cast<DataRowView ^>(this->dataGridViewMusic->CurrentRow->DataBoundItem)->Row;
		//	this->textBox1->Text = drow[MediaFile::pathKey]->ToString();

		//musicCatalog->Rows[this->dataGridViewMusic->CurrentRow]->

		/*
		String ^ pathStr = this->dataGridViewMusic->CurrentRow->Cells[MediaFile::pathKey]->Value->ToString();

		DataRow ^ drow = musicCatalog->Rows[0];
		this->textBox1->Text = drow[MediaFile::pathKey]->ToString();
		*/

		//DataRow ^ row = this->musicCatalog->Rows->F

		//	row = this->musicCatalog->Select(MediaFile::pathKey + " == " + pathStr);

		// int index = this->dataGridViewMusic->CurrentCell->RowIndex;

		//	String ^ pfadStr = this->dataGridViewMusic->CurrentRow->Cells[0]->Value->ToString();
		//	DataRow ^ row = gcnew DataRow(this->musicCatalog->Rows->Find(pfadStr));
		//	this->textBox1->Text = row->ItemArray[2]->ToString();

		//	this->textBox1->Text = pfadStr;
		//	this->textBox1->Text = this->musicCatalog->Rows[index]->ItemArray["Artist"]->ToString();

		//	DataGridViewRow ^ row = this->dataGridViewMusic->CurrentRow;

		//	musicCatalog->Rows[0]->

		//	this->textBox1->Text = this->dataGridViewMusic->Rows[index]->Cells[0]->Value->ToString();

		//	DataRow ^ row = this->dataGridViewMusic->Rows[index];

		//	this->textBox1->Text = musicCatalog-
	}
	private: System::Void dataGridViewPicture_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		pictureCatalog->getFile(this->dataGridViewPicture->CurrentRow)->play();
	}
	private: System::Void dataGridViewMovie_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		movieCatalog->getFile(this->dataGridViewMovie->CurrentRow)->play();
	}
};
}
