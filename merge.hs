maior :: Ord t => t -> t -> t
maior a b | a>= b = a
          | otherwise = b

merge :: Ord t => [t] -> [t] -> [t]
merge (x:xs) [] = (x:xs)
merge [] (y:ys) = (y:ys)
merge (x:xs) (y:ys) | y `maior` x == y = x : (merge xs (y:ys))
                    | otherwise = y : (merge (x:xs) ys)

myLength :: Ord t => [t] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

yeah :: Ord t => Int -> [t] -> [Int]
yeah b x = [b.. (myLength x)-1]

drop' :: Ord t => Int -> [t] -> [t]
drop' _ [] = []
drop' a (x:xs) = getindexes(yeah a(x:xs)) (x:xs)

gotyou:: Ord t => Int -> [t] -> [Int]
gotyou b x = [0..(b-1)]

getindexes :: Ord t => [Int] -> [t] -> [t]
getindexes _ [] = []
getindexes [] _ = []
getindexes (a:as) bs = (bs !! a) : (getindexes as bs) 

take' :: Ord t => Int -> [t] -> [t]
take' a (x:xs) = getindexes(gotyou a(x:xs)) (x:xs)

takehalf :: Ord t => [t] -> [t]
takehalf [] = []
takehalf bs = take' (div(myLength bs)2) (bs)

drophalf :: Ord t => [t] -> [t]
drophalf [] = []
drophalf bs = drop' (div(myLength bs)2) (bs)

mergesort :: Ord t => [t] -> [t]
mergesort [] = []
mergesort [xs] = [xs]
mergesort xs = merge (mergesort (takehalf xs)) (mergesort (drophalf xs))

getNumbers :: String -> [Int]
getNumbers str = map read $ words str :: [Int]

dsa_hss c = do
    conteudo <- readFile c
    let numeros = getNumbers conteudo
    print (mergesort numeros)