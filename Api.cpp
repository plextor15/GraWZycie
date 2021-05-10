#include "Api.h"

void Api::GameLoop(){
    while (true)
    {
        Analiza();
        Przejscie();
        View(); //nie ma juz Plansza TMP
    }
    return;
}

void Api::View()
{
   static int dx=10, dy=10;
   for(int i=0; i< Wysokosc; i++) {
      for(int j=0; j<Szerokosc; j++) {
          //GetSzerokosc
         if(Plansza[i][j].CzyZyje()) ::Rectangle(m_hdc, i*dx, j*dy, (i+1)*dx, (j+1)*dy); //cout<<'A';
         else ::Ellipse(m_hdc, i*dx, j*dy, (i+1)*dx, (j+1)*dy); //cout<<' ';
      }
   }
   Sleep(1000);
}

void Api::InitAPI(HWND hwnd)
{
//   m_hwnd = hwnd;
   m_hdc = GetDC( hwnd );
}
