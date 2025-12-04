import matplotlib.pyplot as plt

# Listas para armazenar os dados lidos do arquivo
tamanhos_n = []
tempos_ineficiente = []
tempos_eficiente = []

nome_arquivo = 'dados.txt'

try:
    print(f"Lendo dados de {nome_arquivo}...")
    
    with open(nome_arquivo, 'r') as f:
        for linha in f:
            # O formato esperado é: N Tempo Ineficiente Tempo Eficiente
            partes = linha.split()
            
            # Pula linhas vazias ou mal formatadas
            if len(partes) < 3:
                continue
                
            n = int(partes[0])
            t_in = int(partes[1])
            t_ef = int(partes[2])
            
            tamanhos_n.append(n)
            tempos_ineficiente.append(t_in)
            tempos_eficiente.append(t_ef)

    if not tamanhos_n:
        print("Erro: O arquivo está vazio ou não pôde ser lido corretamente.")
        exit()

    # Configurando o tamanho da imagem
    plt.figure(figsize=(10, 6))

    # Plotando a linha da Solução Ineficiente (Vermelha)
    plt.plot(tamanhos_n, tempos_ineficiente, 
             color='red', marker='o', linestyle='-', linewidth=2, 
             label='Ineficiente O(N²)')

    # Plotando a linha da Solução Eficiente (Azul)
    plt.plot(tamanhos_n, tempos_eficiente, 
             color='blue', marker='x', linestyle='--', linewidth=2, 
             label='Eficiente STL O(N log N)')

    # Textos e Legendas
    plt.title('Comparação de Desempenho: Uniqueness (AtCoder)', fontsize=14)
    plt.xlabel('Tamanho da Entrada (N)', fontsize=12)
    plt.ylabel('Tempo de Processamento (ms)', fontsize=12)
    plt.legend(fontsize=12) # Mostra a caixinha com os nomes das linhas
    plt.grid(True, linestyle='--', alpha=0.7) # Grade de fundo

    # Salvar o gráfico como imagem
    plt.savefig('grafico_comparativo.png', dpi=300)
    print("Sucesso! O gráfico foi salvo como 'grafico_comparativo.png'")
    
    try:
        plt.show()
    except:
        pass

except FileNotFoundError:
    print(f"ERRO: O arquivo '{nome_arquivo}' não foi encontrado.")
    print("Certifique-se de rodar o código C++ primeiro: ./generator > dados.txt")