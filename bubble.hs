maior :: Ord t => t -> t -> t
maior a b | a>= b = a
          | otherwise = b


bubble :: Ord t => [t] -> [t]
bubble [] = []
bubble [b] = [b]
bubble (a:b:xs) | a > b = b : bubble(a:xs)
                | otherwise = a : bubble (b:xs)

bubblesort :: Ord t => [t] -> [t]
bubblesort [] = []
bubblesort xs = makehappen (myLength xs) (xs)

myLength :: Ord t => [t] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

makehappen :: Ord t => Int -> [t] -> [t]
makehappen 0 xs = xs
makehappen vezes xs = makehappen (vezes-1) (bubble xs)




getNumbers :: String -> [Int]
getNumbers str = map read $ words str :: [Int]

dsa_hss c = do
    conteudo <- readFile c
    let numeros = getNumbers conteudo
    print (bubblesort numeros)