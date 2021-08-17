<?php
$university         = "SAKARYA ÜNİVERSİTESİ";
$department         = "BİLİŞİM SİSTEMLERİ MÜHENDİSLİĞİ";
$lessonName         = "SİSTEM YÖNETİCİLİĞİ";
$teacher            = "Öğr.Gör.Dr. BARAN KAYNAK";
$studentFullName    = "ENGİN YENİCE";
$studentNumber      = "S201200019";

?>

<!doctype html>
<html lang="tr">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.0/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-KyZXEAg3QhqLMpG8r+8fhAXLRk2vvoC2f3B09zVXn8CA5QIVfZOJ3BCsw2P0p/We" crossorigin="anonymous">

    <title><?=$lessonName?> KISA ODEV</title>
  </head>
  <body>

  <div class="container mt-2">
  <div class="card">
  <div class="card-header">
    Genel Bilgiler
  </div>
  <div class="card-body">
    <p class="card-text"><strong>Üniversite :</strong> <?=$university?></p>
    <p class="card-text"><strong>Bölüm      :</strong> <?=$department?></p>
    <p class="card-text"><strong>Ders       :</strong> <?=$lessonName?></p>
    <p class="card-text"><strong>Dersi Veren:</strong> <?=$teacher?></p>
    </hr>
    <p class="card-text"><strong>Öğrenci No:</strong> <?=$studentNumber?></p>
    <p class="card-text"><strong>Öğrenci   :</strong> <?=$studentFullName?></p>
    </hr>
    <p class="card-text"><strong>Rastgele bir resim</strong></p>
    <img src="https://picsum.photos/400/300" class="img-fluid" alt="Rastgele bir resim">
  </div>
</div>
</div>


    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-U1DAWAznBHeqEIlVSCgzq+c9gqGAJn5c/t99JyeKa9xxaYpSvHU5awsuZVVFIhvj" crossorigin="anonymous"></script>
  </body>
</html>