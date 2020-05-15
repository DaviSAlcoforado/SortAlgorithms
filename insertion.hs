
maior :: Ord t => t -> t -> t
maior a b | a >= b = a
          | otherwise = b

justinsert :: Ord t => t -> [t] -> [t]
justinsert x [] = [x]
justinsert a (x:xs) | maior a x == x = a : x : xs
                    | otherwise = x : justinsert a xs

insertionsort :: Ord t => [t] -> [t]
insertionsort [] = []
insertionsort (x:xs) = [a | a<-justinsert x (insertionsort xs)]

getNumbers :: String -> [Int]
getNumbers str = map read $ words str :: [Int]

dsa_hss c = do
    conteudo <- readFile c
    let numeros = getNumbers conteudo
    print (insertionsort numeros)