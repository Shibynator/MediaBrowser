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
			this->tabPagePicture = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewPicture = (gcnew System::Windows::Forms::DataGridView());
			this->tabPageMovie = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewMovie = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewMusic = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->tabControlCatalog->SuspendLayout();
			this->tabPageMusic->SuspendLayout();
			this->tabPagePicture->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPicture))->BeginInit();
			this->tabPageMovie->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMovie))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMusic))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->dateiToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(3, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(722, 24);
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
			this->dateiToolStripMenuItem->Size = System::Drawing::Size(46, 22);
			this->dateiToolStripMenuItem->Text = L"Datei";
			// 
			// verzeichnissImportierenToolStripMenuItem
			// 
			this->verzeichnissImportierenToolStripMenuItem->Name = L"verzeichnissImportierenToolStripMenuItem";
			this->verzeichnissImportierenToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->verzeichnissImportierenToolStripMenuItem->Text = L"Verzeichniss importieren...";
			this->verzeichnissImportierenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainView::verzeichnissImportierenToolStripMenuItem_Click);
			// 
			// beendenToolStripMenuItem
			// 
			this->beendenToolStripMenuItem->Name = L"beendenToolStripMenuItem";
			this->beendenToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->beendenToolStripMenuItem->Text = L"Beenden";
			this->beendenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainView::beendenToolStripMenuItem_Click);
			// 
			// tabControlCatalog
			// 
			this->tabControlCatalog->Controls->Add(this->tabPageMusic);
			this->tabControlCatalog->Controls->Add(this->tabPagePicture);
			this->tabControlCatalog->Controls->Add(this->tabPageMovie);
			this->tabControlCatalog->Location = System::Drawing::Point(6, 22);
			this->tabControlCatalog->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabControlCatalog->Name = L"tabControlCatalog";
			this->tabControlCatalog->SelectedIndex = 0;
			this->tabControlCatalog->Size = System::Drawing::Size(1100, 395);
			this->tabControlCatalog->TabIndex = 1;
			// 
			// tabPageMusic
			// 
			this->tabPageMusic->Controls->Add(this->dataGridViewMusic);
			this->tabPageMusic->Location = System::Drawing::Point(4, 22);
			this->tabPageMusic->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPageMusic->Name = L"tabPageMusic";
			this->tabPageMusic->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPageMusic->Size = System::Drawing::Size(1092, 369);
			this->tabPageMusic->TabIndex = 0;
			this->tabPageMusic->Text = L"Musik";
			this->tabPageMusic->UseVisualStyleBackColor = true;
			// 
			// tabPagePicture
			// 
			this->tabPagePicture->Controls->Add(this->dataGridViewPicture);
			this->tabPagePicture->Location = System::Drawing::Point(4, 22);
			this->tabPagePicture->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPagePicture->Name = L"tabPagePicture";
			this->tabPagePicture->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPagePicture->Size = System::Drawing::Size(1092, 369);
			this->tabPagePicture->TabIndex = 1;
			this->tabPagePicture->Text = L"Bilder";
			this->tabPagePicture->UseVisualStyleBackColor = true;
			// 
			// dataGridViewPicture
			// 
			this->dataGridViewPicture->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewPicture->Location = System::Drawing::Point(2, 2);
			this->dataGridViewPicture->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridViewPicture->Name = L"dataGridViewPicture";
			this->dataGridViewPicture->RowTemplate->Height = 33;
			this->dataGridViewPicture->Size = System::Drawing::Size(1092, 371);
			this->dataGridViewPicture->TabIndex = 1;
			// 
			// tabPageMovie
			// 
			this->tabPageMovie->Controls->Add(this->dataGridViewMovie);
			this->tabPageMovie->Location = System::Drawing::Point(4, 22);
			this->tabPageMovie->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPageMovie->Name = L"tabPageMovie";
			this->tabPageMovie->Size = System::Drawing::Size(1092, 369);
			this->tabPageMovie->TabIndex = 2;
			this->tabPageMovie->Text = L"Videos";
			this->tabPageMovie->UseVisualStyleBackColor = true;
			// 
			// dataGridViewMovie
			// 
			this->dataGridViewMovie->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewMovie->Location = System::Drawing::Point(2, 2);
			this->dataGridViewMovie->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridViewMovie->Name = L"dataGridViewMovie";
			this->dataGridViewMovie->RowTemplate->Height = 33;
			this->dataGridViewMovie->Size = System::Drawing::Size(1094, 372);
			this->dataGridViewMovie->TabIndex = 1;
			// 
			// dataGridViewMusic
			// 
			this->dataGridViewMusic->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewMusic->Location = System::Drawing::Point(0, 0);
			this->dataGridViewMusic->Name = L"dataGridViewMusic";
			this->dataGridViewMusic->Size = System::Drawing::Size(712, 369);
			this->dataGridViewMusic->TabIndex = 0;
			// 
			// MainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(722, 444);
			this->Controls->Add(this->tabControlCatalog);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MainView";
			this->Text = L"MainView";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControlCatalog->ResumeLayout(false);
			this->tabPageMusic->ResumeLayout(false);
			this->tabPagePicture->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPicture))->EndInit();
			this->tabPageMovie->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMovie))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMusic))->EndInit();
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
};
}
