menor :: Ord t => t -> t -> t
menor a b | b >= a = a
          | otherwise = b

menornalista :: Ord t => [t] -> t
menornalista [x] = x 
menornalista (x:xs) = menor x (menornalista xs)


selectionsort :: Ord t => [t] -> [t]
selectionsort [] = []
selectionsort xs = menornalista xs : selectionsort(remove (menornalista xs) xs)

remove :: Ord t => t -> [t] -> [t]
remove _ [] = []
remove a (x:xs) | a == x = xs
                | otherwise = x: remove a xs


getNumbers :: String -> [Int]
getNumbers str = map read $ words str :: [Int]

dsa_hss c = do
    conteudo <- readFile c
    let numeros = getNumbers conteudo
    print (selectionsort numeros)