#include <iostream>
#include <string>
using namespace std;
class yayin
   {
   private:
      string baslik;
      float fiyat;
   public:
      virtual void bilgiAl()
      {
      cout << "Basligi girin:"; cin >> baslik;
      cout << "Fiyati girin:"; cin >> fiyat;
      }
      virtual void bilgiVer()
      {
      cout << "Baslik:" << baslik << endl;
      cout << "Fiyat:" << fiyat << endl;
      }
      virtual bool isOversize()=0;
   };
class kitap : public yayin
   {
   private:
      int sayfa;
   public:
      void bilgiAl()
      {
      yayin::bilgiAl();
      cout << "Sayfa sayisini girin:"; cin >> sayfa;
      }
      void bilgiVer()
      {
      cout << endl;
      yayin::bilgiVer();
      cout << "Sayfa sayisi:" << sayfa << endl;
      }
      bool isOversize()
      {
      return ((sayfa>800) ? true : false);
      }
   };
class kaset : public yayin
   {
   private:
      int zaman;
   public:
      void bilgiAl()
      {
      yayin::bilgiAl();
      cout << "Zamani girin:"; cin >> zaman;
      }
      void bilgiVer()
      {
      cout << endl;
      yayin::bilgiVer();
      cout << "Zaman:" << zaman << endl;
      }
      bool isOversize()
      {
      return ((zaman>90) ? true : false);
      }
   };
int main()
   {
   yayin* yayindizi[50];
   int n=0;
   char secim;
   do
   {
      cout << endl;
      cout << "Kitap ya da kaset icin bilgi girin(p/t):";
      cin >> secim;
      if (secim=='p')
         yayindizi[n] = new kitap;
      else
         yayindizi[n] = new kaset;
      yayindizi[n++]->bilgiAl();
      cout << "Baska girin(e/h):"; cin >> secim;
      } while (secim=='e');

   cout << endl;

   for (int i=0;i<n;i++)
      {
      yayindizi[i]->bilgiVer();
      if (yayindizi[i]->isOversize())
         cout << "Oversize.." << endl;
      }
   cout << endl;

   return 0;
   }
