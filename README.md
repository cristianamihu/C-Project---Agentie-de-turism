O aplicație C++ in care folosesc paradigma orientat obiect. Aplicatia are interfata utilizator tip consola si utilizeaza procesul de dezvoltare bazat pe functionalitati (Feature driven development).

Am folosit o arhitectura stratificata (UI / Services(GRASP Controller) / Repository) si am creat clase pentru: Domain, Service, UI, Repository. Toate functiile necesare sunt specificate si testate (Test Code Coverage > 99% la toate modulele in afara de UI). Fara warninguri (in Visual Studio warning level /W4, treat warning as errors)

Initial am folosit clasa std::string si clasa std::vector din STL (libraria standard C++) apoi am inlocuit clasa std::vector cu o clasa proprie parametrizata (Template) care implementeaza o lista folosind structura de date lista inlantuita.

Validarea datelor. Utilizatorul este anunțat printr-un mesaj daca: introduce valori de intrare gresite; incearca sa adauge o entitate de doua ori, incearca sa stearga / modifice o entitate inexistenta (se vor folosi exceptii).

Const Correctness:

– am folosit calificativul const pentru variabile/parametrii care nu sunt modificati

– am folosit calificativul const pentru metode care nu modifica starea obiectelor

– am transmis parametrii prin const & peste tot unde este posibil

– am evitat copierea obiectelor cand nu a fost necesar.


Aplicatia permite gestiunea unei liste de oferte turistice. Oferta: denumire, destinatie, tip, pret.

Lista de functionalitati:

   F1. Adaugare oferta
   
   F2. Stergere oferta
   
   F3. Modificare oferta
   
   F4. Afisarea tuturor ofertelor
   
   F5. Cautare oferta
   
   F6. Filtrare oferta dupa destinatie
   
   F7. Filtrare oferta dupa pret
   
   F8. Sortare oferta dupa denumire
   
   F9. Sortare oferta dupa destinatie
   
   F10. Sortare oferta dupa tip si pret


![image](https://github.com/cristianamihu/C-Project---Agentie-de-turism/assets/128689630/5870fb6c-15a5-40d4-8ee6-73db7cf9035c)

![image](https://github.com/cristianamihu/C-Project---Agentie-de-turism/assets/128689630/424f29f6-7b28-4f44-b848-812ae67266fa)
