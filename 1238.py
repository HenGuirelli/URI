class Combinador:
    def __init__(self, string1, string2):
        self.string1 = string1
        self.string2 = string2
        
    def _adc_caractere_string1(self, cont: int)->str:
        if cont >= len(self.string1):
            return ''
        return self.string1[cont]

    def _adc_caractere_string2(self, cont: int) -> str:
        if cont >= len(self.string2):
            return ''
        return self.string2[cont]
    
    def combinar(self):
        tam1 = len(self.string1)
        tam2 = len(self.string2)
        
        cont = 0
        combinado = ''
        while tam1 != 0 or tam2 != 0:
            combinado += self._adc_caractere_string1(cont)
            combinado += self._adc_caractere_string2(cont)

            cont += 1
            tam1 -= 1 if tam1 > 0 else 0
            tam2 -= 1 if tam2 > 0 else 0
        return combinado
            
    

qtde = int(input())
for i in range(qtde):
    string1, string2 = input().split(' ')
    
    
    comb = Combinador(string1, string2)
    print(comb.combinar())

    
    
