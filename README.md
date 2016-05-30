# Wodzynski Piotr Tadeusz
## Symulator regat

Zamierzam napisać symulator regat. Obiektami będą **łódki**, które będą miały parametry takie jak: 

- wielkość żagla,
- masę balastu, 
- długość,
- umiejętności załogi,
- kurs.

Wszystkie parametry będą dobierane losowo z zaznaczeniem faktu, że wielkość żagla będzie wpływała na losowanie masy balastu i długości, natomiast będą zwracać prędkość jachtu i odległość do następnej boi zaplanowanym kursem (pod wiatr nie można płynąć). Kolejnymi obiekatmi będą boje których pozycja będzie losowana. 

Będzie także klasa wiatru która będzie miała cztery parametry:

- początkowy kierunek i siłę wiatru,
- końcowy kierunek i siłę wiatru.

Te parametry będą losowane i aktualny stan wiatru będzie się zmieniać liniowo wraz z przebiegiem regat. 

Ostatnią klasą będzie stan morza, który będzie przejmować stan wiatru i dobierać z opóźnieniem (morze musi się rozbujać) skalę Beufoarta. Na prędkość i pozycję łódki oczywiście będzie wpływać akutalny stan morza i wiatru który będzie uaktualniany co sekundę w przypadku mocnych wiatrów oczywiście lódki cięższe poradzą sobie lepiej od lżejszych, a w przypadku słabych, lżejsze wypadną lepiej, natomiast jeżeli łódka będzie zbyt lekka umiejętności załogi zbyt małe a siła wiatru będzie zbyt duża to łódka się wywali (`masa * umiejętności < siła wiatru * n`, `n` - parametr który zostanie dobrany na podstawie testów).
