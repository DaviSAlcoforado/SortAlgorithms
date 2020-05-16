quicksort :: Ord t => [t] -> [t]
quicksort [] = []
quicksort (pivo:resto) = (quicksort menoresqueopivo) ++ [pivo] ++ (quicksort maioresqueopivo)
        where
                maioresqueopivo = [elemento | elemento<-resto, elemento >= pivo]
                menoresqueopivo = [elemento | elemento<-resto, elemento < pivo]
                
getNumbers :: String -> [Int]
getNumbers str = map read $ words str :: [Int]

dsa_hss c = do
    conteudo <- readFile c
    let numeros = getNumbers conteudo
    print (quicksort numeros)