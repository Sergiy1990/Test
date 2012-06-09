#include<iostream>
#include<fstream>
#include<stdio.h>


using namespace std;

int main(void)
{
	unsigned long int count=0,i=0,cn=0;
	char HBuff=0;
	char ch=0;

cout<<"Enter E or e to encrypt data.\n"
	<<"Enter D or d to decrypt data.\n";

cin.get(ch);
	
if(ch=='E'||ch=='e'||ch=='D'||ch=='d')
{
		if(ch=='E'||ch=='e')
		{
			/////////////////ENCRYPT//////////////////////////	
				FILE *SourceFile=fopen("text.txt","r");
				
		//////////Pidrahynok k-sti bait v text.txt		
				
				do
				{
					cn=fgetc(SourceFile);
			
					if(cn=='\n')
						{
							count=count+1;
						}

					if(cn!=EOF)
						{
							count=count+1;
						}	

				}
				while(cn!=EOF);
					
			
				cout<<"Text has "<<count<<" char's\n";

				fclose(SourceFile);

				char * text=new char [count];

				ifstream instrm ("text.txt", std::ios::binary); 
				
				instrm.read(text, count); 

				instrm.close();


				for(i=0;i<count;i++)
				{
					HBuff=text[i];
					HBuff=unsigned char(HBuff)>>4;
					
					text[i]=unsigned char(text[i])<<4;
					text[i]=(text[i])|(HBuff);

					text[i]=text[i]^0xFF;
				}

						
			 ofstream outstrm ("EncryptFile.txt",std::ios::binary);

			 if(outstrm.is_open())
				{	
					for(i = 0; i < count; i++) 
					{
					  outstrm.write((text+i), sizeof(char)); 
					}
	
				  outstrm.close();

				 }
			 delete []text;
		}

		else
		{
				///////////////DECRYPT//////////////
			FILE *EncryptFile=fopen("EncryptFile.txt","r");
				
				do
				{
					cn=fgetc(EncryptFile);
			
					if(cn=='\n')
						{
							count=count+1;
						}

					if(cn!=EOF)
						{
							count=count+1;
						}	

				}
				while(cn!=EOF);
				
				cout<<"Text has "<<count<<" char's";

				fclose(EncryptFile);

				char * text=new char [count];

				ifstream instrm ("EncryptFile.txt", std::ios::binary); 
				
				instrm.read(text, count); 

				instrm.close();

				
				for(i=0;i<count;i++)
				{
					text[i]=text[i]^0xFF;
					HBuff=text[i];
					HBuff=unsigned char(HBuff)<<4;
					
					text[i]=unsigned char(text[i])>>4;
					text[i]=(text[i])|(HBuff);

				}


			 ofstream outstrm ("DecryptFile.txt",std::ios::binary);

			 if(outstrm.is_open())
				{	
					for(i = 0; i < count; i++) 
					{
					  outstrm.write((text+i), sizeof(char)); 
					}
					

				  outstrm.close(); 

				}
			 delete []text;
			
		}
	
}

else cout<<"Enter correct data\n";


	cin.get();
	cin.get();

	return 0;
}
