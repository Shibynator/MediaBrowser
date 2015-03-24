#pragma once

#include "MusicCatalog.h"
#include "PictureCatalog.h"
#include "MovieCatalog.h"

#include "MusicFile.h"
#include "PictureFile.h"
#include "MovieFile.h"

namespace MediaBrowser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Zusammenfassung für MainView
	/// </summary>
	public ref class MainView : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::TabControl^  tabControlCatalog;
	private: System::Windows::Forms::TabPage^  tabPageMusic;
	private: System::Windows::Forms::DataGridView^  dataGridViewMusic;

	private: System::Windows::Forms::TabPage^  tabPagePicture;
	private: System::Windows::Forms::TabPage^  tabPageMovie;

	private: System::Windows::Forms::DataGridView^  dataGridViewPicture;
	private: System::Windows::Forms::DataGridView^  dataGridViewMovie;


	private:
			MusicCatalog musicCatalog;
			PictureCatalog pictureCatalog;
			MovieCatalog movieCatalog;

	public:
		MainView(void)
		{
			InitializeComponent();

			dataGridViewMusic->AutoGenerateColumns = false;
			dataGridViewMusic->DataSource = musicCatalog.getList();

			DataGridViewColumn ^ column = gcnew DataGridViewTextBoxColumn();
			column->DataPropertyName = "title";
			column->Name = "Pfad";
			dataGridViewMusic->Columns->Add(column);

			dataGridViewPicture->DataSource = pictureCatalog.getList();
			dataGridViewMovie->DataSource = movieCatalog.getList();

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
			this->tabPageMovie = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewPicture = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewMovie = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->tabControlCatalog->SuspendLayout();
			this->tabPageMusic->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMusic))->BeginInit();
			this->tabPagePicture->SuspendLayout();
			this->tabPageMovie->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPicture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMovie))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->dateiToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1535, 40);
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
			this->tabControlCatalog->Location = System::Drawing::Point(12, 43);
			this->tabControlCatalog->Name = L"tabControlCatalog";
			this->tabControlCatalog->SelectedIndex = 0;
			this->tabControlCatalog->Size = System::Drawing::Size(1123, 760);
			this->tabControlCatalog->TabIndex = 1;
			// 
			// tabPageMusic
			// 
			this->tabPageMusic->Controls->Add(this->dataGridViewMusic);
			this->tabPageMusic->Location = System::Drawing::Point(4, 34);
			this->tabPageMusic->Name = L"tabPageMusic";
			this->tabPageMusic->Padding = System::Windows::Forms::Padding(3);
			this->tabPageMusic->Size = System::Drawing::Size(1115, 722);
			this->tabPageMusic->TabIndex = 0;
			this->tabPageMusic->Text = L"Musik";
			this->tabPageMusic->UseVisualStyleBackColor = true;
			// 
			// dataGridViewMusic
			// 
			this->dataGridViewMusic->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewMusic->Location = System::Drawing::Point(3, 3);
			this->dataGridViewMusic->Name = L"dataGridViewMusic";
			this->dataGridViewMusic->RowTemplate->Height = 33;
			this->dataGridViewMusic->Size = System::Drawing::Size(989, 646);
			this->dataGridViewMusic->TabIndex = 0;
			// 
			// tabPagePicture
			// 
			this->tabPagePicture->Controls->Add(this->dataGridViewPicture);
			this->tabPagePicture->Location = System::Drawing::Point(4, 34);
			this->tabPagePicture->Name = L"tabPagePicture";
			this->tabPagePicture->Padding = System::Windows::Forms::Padding(3);
			this->tabPagePicture->Size = System::Drawing::Size(1115, 722);
			this->tabPagePicture->TabIndex = 1;
			this->tabPagePicture->Text = L"Bilder";
			this->tabPagePicture->UseVisualStyleBackColor = true;
			// 
			// tabPageMovie
			// 
			this->tabPageMovie->Controls->Add(this->dataGridViewMovie);
			this->tabPageMovie->Location = System::Drawing::Point(4, 34);
			this->tabPageMovie->Name = L"tabPageMovie";
			this->tabPageMovie->Size = System::Drawing::Size(1115, 722);
			this->tabPageMovie->TabIndex = 2;
			this->tabPageMovie->Text = L"Videos";
			this->tabPageMovie->UseVisualStyleBackColor = true;
			// 
			// dataGridViewPicture
			// 
			this->dataGridViewPicture->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewPicture->Location = System::Drawing::Point(3, 6);
			this->dataGridViewPicture->Name = L"dataGridViewPicture";
			this->dataGridViewPicture->RowTemplate->Height = 33;
			this->dataGridViewPicture->Size = System::Drawing::Size(989, 646);
			this->dataGridViewPicture->TabIndex = 1;
			// 
			// dataGridViewMovie
			// 
			this->dataGridViewMovie->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewMovie->Location = System::Drawing::Point(3, 3);
			this->dataGridViewMovie->Name = L"dataGridViewMovie";
			this->dataGridViewMovie->RowTemplate->Height = 33;
			this->dataGridViewMovie->Size = System::Drawing::Size(989, 646);
			this->dataGridViewMovie->TabIndex = 1;
			// 
			// MainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1535, 854);
			this->Controls->Add(this->tabControlCatalog);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainView";
			this->Text = L"MainView";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControlCatalog->ResumeLayout(false);
			this->tabPageMusic->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMusic))->EndInit();
			this->tabPagePicture->ResumeLayout(false);
			this->tabPageMovie->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPicture))->EndInit();
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
		String ^ folderPath;
		String ^ endingMusic;
		String ^ endingPicture;
		String ^ endingMovie;
		endingMusic = "\\*.mp3";
		endingPicture = "\\*.jpeg";
		endingMovie = "\\*.mp4";

		FolderBrowserDialog ^ folderDialog = gcnew FolderBrowserDialog();

		if (folderDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			folderPath = folderDialog->SelectedPath;

			WIN32_FIND_DATA FindFileData;
			HANDLE hFind;

			hFind = FindFirstFile((wchar_t*)(Runtime::InteropServices::Marshal::StringToHGlobalUni(folderPath + endingMusic).ToPointer()), &FindFileData);
			if (hFind == INVALID_HANDLE_VALUE)
			{
				//	FindFirstFile failed
			}
			else
			{
				do
				{
					//Skip directories
					if (FILE_ATTRIBUTE_DIRECTORY & FindFileData.dwFileAttributes)
						continue;

					String^ const strFilename = gcnew String(FindFileData.cFileName);
					String^ const strTitle = gcnew String("Title");
					String^ const strArtist = gcnew String("Artist");
					String^ const strAlbumartist = gcnew String("Albumartist");
					String^ const strAlbum = gcnew String("Album");
					String^ const strGenre = gcnew String("Genre");
					String^ const strDuration = gcnew String("00:11:22");
					String^ const strDateCreation = "345678";
					String^ const strDateModified = "987655";

			/*		DateTime datecreation;
					datecreation.FromFileTime((FindFileData.ftCreationTime.dwHighDateTime << 32) + FindFileData.ftCreationTime.dwLowDateTime); 

					DateTime datemodified;
					datecreation.FromFileTime((FindFileData.ftLastWriteTime.dwHighDateTime << 32) + FindFileData.ftLastWriteTime.dwLowDateTime); 
			*/
			//		String^ const str3 = Convert::ToString(fileTime.wDay) + "." + Convert::ToString(fileTime.wMonth) + "." + Convert::ToString(fileTime.wYear);
		//			String^ const str4 = folderPath + "\\" + strFilename;

					MusicFile ^ musicFile = gcnew MusicFile(folderPath + "\\" + strFilename, strDateCreation, strDateModified, strTitle, strArtist, strAlbumartist, strAlbum, strGenre, strDuration);
					this->musicCatalog.add(musicFile);
					delete musicFile;
					dataGridViewMusic->Refresh();

				} while (FindNextFile(hFind, &FindFileData));

				FindClose(hFind);
			}

		}
		else
		{
		//	folderPath = "undef";
		}
	}
};
}
