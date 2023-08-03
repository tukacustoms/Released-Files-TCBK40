<!-- README.pt-BR.md (Portuguese - Brazil) -->
# Released-Files-TCBK40

# TCBK40

  Bem-vindo ao projeto TCBK40, um teclado personalizado de 40% com RGB, cuidadosamente desenvolvido do zero pela Tuka Customs. Inspirado no layout HHK8, este teclado tem como objetivo ser uma opção compacta e satisfatória tanto para testes comunitários do Firmware QMK quanto para uso diário de entusiastas e criadores de tecnologia.

![keyboard-layout](https://user-images.githubusercontent.com/115516996/214220018-d1240622-77c8-433f-96e1-704550308988.png)

  Inicialmente, este projeto foi criado para descobrir todos os elementos necessários para concluir a primeira ideia de teclado, o TCBK60, o teclado principal criado pela Tuka Customs.

# Como tudo se iniciou?

  A jornada do TCBK40 começou com um PCB personalizado projetado para o TCBK60, o teclado personalizado original da Tuka Customs. No entanto, esse projeto inicial enfrentou desafios devido a um firmware personalizado desatualizado, que continha muitos arquivos e algoritmos desnecessários. Apesar de tentativas bem-sucedidas de compilação, ficou evidente que era necessário uma versão de teclado mais simples, que apresentasse camadas personalizadas, mantendo os mesmos componentes.

  A inspiração surgiu ao recordar um antigo projeto de macro-pad, o que despertou a ideia de utilizar uma placa Pro Micro pré-construída. Essa decisão ofereceu várias vantagens, incluindo a conveniência de soldar o Pro Micro ao PCB finalizado e a inclusão de um conector USB-C, conhecido por suas capacidades superiores e ampla popularidade no mercado atualmente.
  
  ![image](https://user-images.githubusercontent.com/115516996/214223540-ccb4da91-337c-464e-a0c2-f939b0339db3.png)

# Quais seriam os possiveis micro controladores e porque o Pro micro (Atmega32u4)?

  Atualmente, temos muitos processadores que podem ser utilizados para criar um teclado personalizado, o que torna a escolha inicial um pouco difícil. Neste projeto, não foi diferente, e os processadores escolhidos foram o ATmega32u4 (placa Pro Micro), o Raspberry Pi Pico (RP2040) e o famoso processador STM32.
 
# Por que nao utilizar o Raspberry PI PICO?

![image](https://user-images.githubusercontent.com/115516996/214224287-f3fde7cd-7b2c-4d5f-add3-9545506abc65.png)
![image](https://user-images.githubusercontent.com/115516996/214224469-b21da7f4-d63d-49b5-b753-f6fb16c284ff.png)

O Raspberry Pi Pico é realmente uma ótima opção como processador principal para uma placa pré-montada a ser adicionada ao TCBK40. Ele possui muitos pinos GPIO, recursos multifuncionais, um processador dual-core Arm Cortex-M0+ e memória interna de 264 kB, com suporte para até 16 MB de flash externo. Além disso, possui recursos I2C e SPI.

O total de GPIOs é mais do que suficiente para criar a série Butter Keyboards, mas possui algumas desvantagens:

Usa uma conexão micro USB, mas pode ser alterado para USB-C usando um shield, porém isso pode consumir alguns GPIOs.
É mais difícil encontrar suprimentos para ele no Brasil.
Utiliza um microprocessador um pouco proprietário, mas hoje em dia a Comunidade QMK tornou possível utilizá-lo no Firmware QMK
  
# Porque nao usar o STM32 Processor

![image](https://user-images.githubusercontent.com/115516996/214225472-ef0a55bd-cbf2-41e1-9166-7d97b0a52f0e.png)

  O processador STM32 é conhecido por ser um dos processadores mais eficientes em termos de custo, sendo super rápido e oferecendo muitos pinos GPIO para uso. Ele possui 64 KB de memória flash, um cristal interno de 4-16 MHz (porém recomendo o uso de um externo), conexão USART, que é incrivelmente útil, além de conexões SPI e I2C. É um microcontrolador poderoso.
  
![image](https://user-images.githubusercontent.com/115516996/214226004-98c2c98f-6d91-45f6-a479-87bae1c894dc.png)
    
  Este é um dos melhores placas de desenvolvimento conhecidos, usados em muitas áreas como impressoras 3D e placas-mãe de máquinas CNC. E para processadores de teclados, é um dos melhores disponíveis. Infelizmente, não foi usado neste projeto apenas porque o ATMEGA32u4 é um processador mais utilizado pela Tuka Customs e é mais conhecido na área, tornando-o mais acessível para todas as pessoas, mais fácil de encontrar e com mais placas de desenvolvimento pré-construídas disponíveis no mercado. No entanto, a família STM32 será a melhor para um PCB personalizado.
  
# Pro Micro - O Processador Escolhido

Para simplificar o processo de design e desenvolvimento, foi feita uma mudança para uma versão mais simples de teclado com camadas personalizadas e componentes compartilhados. Surge o Pro Micro, uma placa baseada no ATmega32u4 com conector USB-C, escolhida por sua ampla popularidade e acessibilidade no mercado.
    
# O Poder do QMK e a Busca por um Firmware Personalizado

Desde que o firmware escolhido foi o QMK para toda a série Butter Keyboards, enquanto a ideia do PCB estava sendo finalizada para criar o case personalizado e torná-lo o mais acessível possível, o firmware personalizado estava sendo estudado para ser criado do zero. O primeiro firmware foi baseado em um teclado padrão 60-ansi, mas tinha um firmware antigo incorporado a ele. Para criar um firmware do zero, foi criado um arquivo baseado em "https://kbfirmware.com/", que estava extremamente desatualizado. Com a ajuda da Comunidade QMK, ele foi corrigido e ajustado para funcionar como deveria, embora ainda possuísse alguns recursos, arquivos e algoritmos desatualizados, o que pode causar problemas ao compilar e gerar o arquivo .hex.

O ponto de virada veio com a descoberta do "qmk new-keyboard" no QMK SYS, que gerou todos os arquivos necessários para um firmware personalizado com algoritmos e arquivos principais atualizados. Isso agilizou o processo de programação, eliminando arquivos desnecessários como "keyboardname.[ch]". O arquivo principal agora passou a ser o info.json, que contém configurações essenciais para detalhes do fabricante, exibição do nome do teclado, bootloader, direção dos diodos, configurações de recursos, configuração de luz RGB, pinos de matriz, especificações do processador, configurações USB e, o mais importante, o layout do teclado.
  
  ![image](https://user-images.githubusercontent.com/115516996/214229763-13981989-774c-45e7-955b-63d56a7eeeec.png)
  
A melhor parte disso é que o arquivo readme.md contém todas as informações do criador do firmware para que qualquer pessoa possa atualizar seu teclado usando-o.

Na versão desatualizada do firmware no QMK, eram necessários os arquivos keyboard.[ch], que continham a posição do layout para cada linha e coluna a serem substituídas. Agora, isso não será mais necessário porque o info.json contém a posição e o tamanho de cada tecla:
  
![image](https://user-images.githubusercontent.com/115516996/214231061-71b2df3c-0252-476f-a71b-959d993328be.png)

# A Customização e Camadas - Aprimorando a Experiência do Usuário

O TCBK40 possui um layout padrão dividido em três camadas, cada uma acessível por meio de uma combinação de teclas. Além disso, o teclado apresenta uma barra de espaço dividida, que pode ser personalizada para qualquer tecla. Esses recursos foram cuidadosamente projetados para maximizar a funcionalidade, ao mesmo tempo em que mantêm a compacticidade.

O layout padrão será dividido em 3 camadas, que serão acessíveis usando duas teclas em conjunto com outras teclas. Além disso, outra característica do teclado é a barra de espaço dividida, que, por padrão, consiste em duas teclas de espaço, mas pode ser alterada para qualquer outra tecla conforme a preferência do usuário. Essas funcionalidades foram incorporadas para oferecer uma experiência de digitação personalizada e eficiente, permitindo ao usuário adaptar o teclado às suas necessidades e preferências individuais.
  
  ![image](https://user-images.githubusercontent.com/115516996/214231836-dbd5726b-e500-45d1-bb0e-21140c98f432.png)

# Problemas e Soluções (Firmware)

Durante o desenvolvimento do firmware personalizado para o TCBK40, encontrei algumas pequenas dificuldades, mas felizmente, a maioria delas foi resolvida rapidamente.

O principal problema surgiu enquanto eu estava preenchendo todas as informações e programando o layout e as funções do teclado. Enquanto ajustava o firmware, percebi que alguns dos arquivos e algoritmos estavam desatualizados, o que causou erros inesperados no processo. Um problema específico estava relacionado ao layout do teclado, onde ocorreu um erro com os argumentos. O layout estava limitado a 39 argumentos, mas eu tinha 41/42 argumentos no layout. Inicialmente, pensei que a barra de espaço dividida poderia estar causando esse problema e considerei combiná-la em uma única barra de espaço para resolver o problema de contagem de argumentos. No entanto, essa solução não surtiu o efeito desejado.

Após uma investigação mais aprofundada e buscando ajuda de outras pessoas, descobri que a pasta "keyboard" continha arquivos desnecessários (Keyboardname.[ch]) e que o arquivo info.json estava faltando uma tecla para ser corretamente mapeado para o teclado. Corrigindo isso com os ajustes necessários e removendo as vírgulas extras no final de cada linha no layout, consegui resolver o problema com sucesso. Com o firmware corrigido, eu o recompilei e gerei o arquivo hex final, pronto para ser gravado no teclado.
  
  ![image](https://user-images.githubusercontent.com/115516996/214233995-651348ac-a381-4cdf-867f-bf3216e4ae58.png)
  
Essa experiência enfatizou a importância de prestar atenção meticulosa aos detalhes e a significância de estar sempre atualizado com as últimas mudanças no desenvolvimento de firmware. Superando esses desafios, pude garantir a estabilidade e funcionalidade do firmware personalizado, criando uma experiência de usuário suave e satisfatória para o teclado TCBK40.

# Schematic

![image](https://user-images.githubusercontent.com/115516996/214237870-b8e84007-0ea6-4141-89db-7ca58d9bb8b3.png)

  O esquematico para o teclado TCBK40 foi direto e bem planejado, com uma consideração cuidadosa dada ao design e às conexões. Para garantir uma representação precisa, um símbolo personalizado e uma "footprint" (layout) foram criados para a placa Pro Micro, que foi selecionada como a placa pré-montada a ser adicionada ao PCB finalizado. Essa decisão permitiu uma integração mais fácil e garantiu a compatibilidade com outros componentes.

  Para facilitar o processo de adicionar o tamanho correto para cada switch de teclado, um layout foi criado usando a ferramenta "http://www.keyboard-layout-editor.com/". Essa plataforma se mostrou uma ferramenta inestimável para visualizar o layout do teclado e fazer ajustes necessários para obter o melhor ajuste e design.

  Quanto à conexão da matriz, o esquema foi cuidadosamente projetado para fornecer indicações visuais claras. Todas as linhas e colunas foram rotuladas explicitamente na placa, tornando mais fácil verificar e conectar os componentes. A conexão horizontal para as linhas foi relativamente simples. No entanto, as colunas apresentaram um desafio único. Para simplificar a programação e aumentar a probabilidade de sucesso, foram escolhidas linhas diagonais para as conexões das colunas.
  
  ![image](https://user-images.githubusercontent.com/115516996/214242807-abb5780d-35d9-42d5-b549-d6f0123d3201.png)
  (Esta é a segunda imagem para visualizar novamente as conexões)

Como consequência, essa abordagem exigiu a utilização de pinos GPIO adicionais ou, alternativamente, a criação de uma matriz personalizada para os switches e a reprogramação de sua posição no arquivo info.json. Essa decisão foi tomada para potencialmente economizar alguns pinos GPIO, embora tenha suas complexidades e a possibilidade de não funcionar perfeitamente.
  

# Case
  Projetar o case para o teclado TCBK40 foi uma etapa crucial no projeto geral. Para garantir um case bem estruturado e esteticamente agradável, o processo começou com a importação do PCB finalizado para o Fusion 360. A utilização do visualizador 3D do Kicad permitiu à equipe visualizar a aparência do teclado com os componentes desejados montados nele, fornecendo informações valiosas sobre o visual final do produto e sua sensação.
  ![front view](https://user-images.githubusercontent.com/115516996/230317285-8d12554d-603a-4e27-bb1d-752aa193ef91.png)
![Back side](https://user-images.githubusercontent.com/115516996/230317276-aa0b36cc-b4ff-4336-866c-8636a7fba0dc.png)

  No entanto, durante essa etapa, enfrentamos um desafio. Alguns modelos 3D de componentes estavam faltando na biblioteca escolhida, especialmente os arquivos no formato STEP. Para superar esse obstáculo, a equipe decidiu importar todos os arquivos STEP dos componentes para simplificar a exportação para o Fusion 360. Dessa forma, cada componente pôde ser colocado em sua posição correta e importado perfeitamente para o design geral.

  O foco principal do design do case foi a criação da "Switch Plate" (placa onde os switches são montados). Como a placa principal do PCB é projetada para ser fixada exclusivamente à "Switch Plate", esse passo foi de extrema importância para a integridade estrutural do teclado. A colocação e quantidade dos espaçadores (standoffs) foram cuidadosamente consideradas para garantir estabilidade e suporte ao teclado durante o uso. Para alcançar o resultado desejado, oito espaçadores foram distribuídos estrategicamente, quatro na parte superior e quatro na parte inferior.

  Para o material da placa, foi escolhido o acrílico transparente (Clear Acrylic). Essa decisão foi tomada para permitir que os diodos na parte superior do PCB fiquem expostos e visíveis, exibindo o PCB personalizado e melhorando a estética do teclado. Em busca da excelência, a Chat GPT, uma IA com notáveis habilidades, provou ser um recurso valioso. Ela ajudou a resolver diversos problemas matemáticos, como determinar os tamanhos e espaçamentos das teclas do teclado. Além disso, forneceu insights sobre questões de programação relacionadas às funcionalidades do teclado, inclusive na criação de um software em Python para editar funções gerais nos arquivos C++ do teclado.

  Continuando com o progresso da "Switch Plate", a equipe aprofundou-se no entendimento do espaçamento correto, dimensionamento e fichas técnicas dos switches MX. Informações valiosas foram obtidas no vídeo de design de cases do Kobuss, que serviu como fonte de inspiração e orientação para o projeto.
https://www.youtube.com/watch?v=DsW-hKeB3mc&t=632s

  Além disso, uma descoberta significativa foi feita na forma de uma ficha técnica da Sparkfun, que apresentava todos os tamanhos recomendados para a montagem do switch e da placa. Armados com esses dados, a equipe realizou as transformações necessárias para converter as unidades de tamanho de polegadas para milímetros, alinhando-se às unidades de trabalho escolhidas no Fusion 360. Como parte do processo de design, medidas precisas foram aprendidas e implementadas para cortar a placa e acomodar os switches.
  
  ![image](https://user-images.githubusercontent.com/115516996/230322543-25ff6450-1e6f-4a34-bcad-76e51166fb2f.png)

  ![image](https://user-images.githubusercontent.com/115516996/230322608-69c2d541-3153-4961-9ac3-b713934f1529.png)

  Além disso, para aprimorar a funcionalidade e a experiência do usuário, uma característica cuidadosa foi introduzida - cortes circulares em cada vértice da placa. Essa decisão de design não apenas permitiu a colocação segura dos switches, mas também possibilitou a troca fácil dos switches sem o risco de danificar a placa. Esse benefício adicional, em conjunto com um design visualmente atraente, aumentou o apelo geral do teclado TCBK40.

  ![another material render](https://github.com/tukacustoms/Released-Files-TCBK40/assets/115516996/b3f183d2-0dcf-4abf-860f-348f29c68e4e)

 # A Potência da IA - Chat GPT em Ação

  Ao longo do projeto, o Chat GPT, um modelo de linguagem de IA, foi inestimável em auxiliar com cálculos matemáticos, dúvidas de programação e otimizações de design. Ele se mostrou uma fonte criativa e conhecedora na busca pela perfeição.
  O Chat GPT também foi uma ferramenta útil para fornecer referências e fontes de inspiração. Quando a equipe precisou de orientação ou informações específicas sobre design de teclados, o Chat GPT foi capaz de direcionar para vídeos, artigos ou sites relevantes, facilitando o processo de pesquisa e aprendizado.
  
# Lessons Learned about Switch Plate Design

  Durante o processo de design da placa de switches para o teclado TCBK40, várias lições valiosas foram aprendidas, o que melhorou significativamente a eficiência e a precisão do projeto.

![Keyboard case v26 close](https://github.com/tukacustoms/Released-Files-TCBK40/assets/115516996/d3682dd1-0710-4e38-ab72-60494f6e0b7b)

1. **Correspondência de Tamanhos e Espaçamento dos Switches**: Inicialmente, a primeira linha de medições estava perfeitamente alinhada, com cada switch espaçado em 1U (19,05 mm) de distância. No entanto, surgiram complicações nas linhas subsequentes devido à presença de diferentes tamanhos de teclas (2-2.25U, 2-1.75U, 7-1.25U). O desafio foi garantir que as distâncias entre os switches na segunda linha correspondessem à colocação dos switches no PCB. Após utilizar o Chat GPT para investigar e pensar logicamente sobre o problema, foi descoberto que a distância de 21,4 mm entre os switches foi alcançada somando-se o primeiro tamanho de tecla com o segundo tamanho de tecla e dividindo por 2. Esse método forneceu um valor aproximado para o espaçamento entre diferentes tamanhos de teclas. Importante ressaltar que os cálculos foram feitos com valores exatos da ficha técnica, mas arredondados para levar em conta variações.

2. **Aprimorando o Design da Placa de Switches com o Keyboard Layout Editor**: Uma abordagem valiosa para o design da placa de switches foi encontrada ao utilizar o site http://www.keyboard-layout-editor.com/. Essa plataforma facilitou a organização e o design do layout desejado, permitindo aos usuários alterar e adicionar tamanhos de teclas, camadas, rotações e cores. Após concluir o layout, ele foi salvo clicando no botão "perma link" e os dados brutos foram copiados para a próxima etapa.

3. **Criando Desenhos Vetoriais para o Design da Placa de Switches**: Construindo sobre o conhecimento da lição anterior, a próxima etapa envolveu a criação de desenhos vetoriais para a placa de switches com base nos dados brutos fornecidos pelo layout do teclado. Isso eliminou a necessidade de medir e calcular manualmente todas as dimensões do zero. Ao visitar o site http://builder.swillkb.com/, os usuários puderam configurar o design da placa, incluindo o tipo de switch, o tipo de estabilizador, os cantos da placa e muito mais. Essa abordagem economizou tempo significativo e garantiu a melhor qualidade para a placa de switches.

Em conclusão, durante a jornada de design da placa de switches, a equipe obteve insights sobre técnicas eficazes de espaçamento para os switches, aproveitou ferramentas inovadoras como o Keyboard Layout Editor e o http://builder.swillkb.com/, e experimentou o poder de usar a assistência de IA (Chat GPT) para resolver desafios de design.
  
# Unindo tudo

O processo de montagem do teclado TCBK40, com seus estabilizadores montados no PCB, envolve várias etapas-chave para garantir uma montagem suave e bem-sucedida:

1. **Componentes SMD e PCB Stencil**: Comece adicionando os componentes de montagem em superfície (SMD) ao PCB. Esses componentes exigem atenção cuidadosa aos detalhes, e é altamente recomendável usar um stencil de PCB para reduzir o risco de danificar os componentes e facilitar a soldagem precisa. Aplique pasta de solda através do stencil nas áreas designadas para os componentes SMD.

2. **Colocação de Componentes e Estabilizadores**: Após os componentes SMD estarem no lugar, adicione os componentes de furo passante ao PCB. Esses componentes geralmente são maiores e mais fáceis de manusear. Além disso, instale os estabilizadores montados no PCB em suas posições designadas.

3. **Posicionamento do Microcontrolador**: O design do teclado TCBK40 incorpora uma placa Pro Micro, que já vem pré-soldada no PCB finalizado. Como a placa Pro Micro ficará entre outros componentes no verso, é melhor deixá-la como o último componente a ser adicionado. Isso garante que ela não obstrua o acesso a outras partes do PCB durante a montagem.

4. **Posicionamento e Soldagem dos Switches**: Para teclados que exigem a soldagem de switches individuais, uma abordagem recomendada é colocar inicialmente alguns switches no PCB principal. Esse passo ajuda a garantir que os switches estejam cor

   ![Keyboard_case_2023-Jul-07_09-18-37PM-000_CustomizedView6189358300](https://github.com/tukacustoms/Released-Files-TCBK40/assets/115516996/56c6411c-5285-478e-bd8b-542953b9d3cf)

# Resolução de Problemas e Soluções durante os Testes.

  Durante a fase de teste do teclado TCBK40, foram encontrados vários problemas que precisaram ser resolvidos para garantir a funcionalidade e usabilidade do teclado. Vamos examinar os problemas enfrentados e as soluções implementadas:

1. **Problemas com a Iluminação RGB**: Inicialmente, durante os testes do teclado sem a soldagem da placa Pro Micro e dos switches, a iluminação RGB não funcionou como esperado. Algumas teclas não acendiam corretamente, e havia discrepâncias de brilho e cor entre os LEDs.

   - Solução: Ao soldar todos os componentes no lugar, o problema da iluminação RGB foi resolvido e ela passou a funcionar corretamente. Isso indica que a soldagem adequada dos componentes é crucial para garantir um funcionamento confiável.

2. **Teclas não Respondendo**: Após soldar os switches e a placa Pro Micro, algumas teclas ainda não registravam as teclas pressionadas durante os testes.

   - Solução: Para corrigir as teclas que não respondiam, o firmware foi cuidadosamente revisado, e possíveis erros no mapa de teclas foram identificados. Após corrigir esses erros, todas as teclas registraram as teclas pressionadas conforme o esperado.

3. **Problemas com LEDs e Brilho**: Ao testar comandos RGB e animações, alguns LEDs não correspondiam aos LEDs da parte superior e foram observadas inconsistências de brilho.

   - Solução: Para resolver os problemas de alinhamento dos LEDs e as inconsistências de brilho, foram realizados testes detalhados para garantir que todos os LEDs estivessem corretamente posicionados e funcionando corretamente. Além disso, ajustes foram feitos no firmware para garantir que as configurações da iluminação RGB fossem precisas e consistentes.

4. **Melhorias no Mapa de Teclas e Camadas**: O mapa de teclas inicial não incluía algumas teclas essenciais para uso diário.

   - Solução: O mapa de teclas do firmware foi refinado e aprimorado para incluir todas as teclas necessárias para uso diário, hobbies de tecnologia, estudos, trabalho e diversão. Isso garante que o teclado seja versátil e adequado para várias tarefas e atividades.

Ao resolver esses problemas e implementar as soluções adequadas, o teclado TCBK40 pode agora proporcionar uma experiência satisfatória ao usuário, com teclas responsivas, iluminação RGB funcional e um mapa de teclas bem projetado adequado para uso diário e outras tarefas. É essencial testar cuidadosamente o teclado e fazer melhorias iterativas para alcançar a funcionalidade e desempenho desejados.

#  Escolhendo os Switches de Teclado Perfeitos

  Escolher os switches de teclado pode ser um desafio, especialmente ao selecionar opções para um produto final. Os switches mecânicos são divididos em 3 tipos: lineares, táteis e clicky.

  Os switches lineares são switches sem bumps que você pode sentir quando pressiona a tecla. Eles são pressionados suavemente e o registro da tecla ocorre antes dela atingir o fundo. A vantagem disso é a resposta rápida do acionamento da tecla, mas isso também resulta na sensibilidade dos switches, já que a corrente começa a passar assim que eles se movem.
  ![image](https://github.com/tukacustoms/TCBK40/assets/115516996/7b9a5ee8-d93d-4560-b252-a01dfdd05c9d)

  Os switches táteis têm um pequeno bump que torna o acionamento tátil quando você pressiona a tecla, proporcionando um clique auditivo suave em cada acionamento. Isso oferece uma ótima experiência de feedback ao digitar, fazendo com que você saiba, pelo toque e som, que tudo está funcionando corretamente.
  ![image](https://github.com/tukacustoms/TCBK40/assets/115516996/14f68b43-ecd7-45ce-9af2-51596671e412)

  Os switches clicky, como o próprio nome sugere, têm um mecanismo que cria um som de clique ao pressionar a tecla. Eles possuem as propriedades dos switches táteis, mas com o clique audível adicionado.
  ![image](https://github.com/tukacustoms/TCBK40/assets/115516996/32aec917-4adf-4d6a-95d3-ecd06c5d035b)


https://pt.aliexpress.com/store/1102816724?spm=a2g0o.detail.0.0.163aNSzPNSzPXC

# Conclusão - Um Trabalho de Paixão e Expertise

  O TCBK40 é o resultado de quase um ano de trabalho árduo, criatividade e resolução de problemas. Desde o design de um firmware e PCB personalizados até a criação de uma caixa visualmente atraente, cada aspecto foi cuidadosamente considerado. A dedicação da Tuka Customs à excelência brilha através da experiência do usuário perfeita proporcionada pelo TCBK40, tornando-o um teclado que vale cada centavo.

  Com uma impressionante combinação de conhecimentos em teclados, hardware, programação, QMK, esquemas, materiais e apresentação, a jornada da Tuka Customs continua a entregar projetos inovadores e inspiradores. À medida que o TCBK40 evolui e cresce, novas ideias e informações continuarão sendo adicionadas, tornando-o um recurso valioso e informativo para entusiastas de teclados em todo o mundo.

![Keyboard_case_2023-Jul-07_09-18-37PM-000_CustomizedView6189358300](https://github.com/tukacustoms/Released-Files-TCBK40/assets/115516996/af208f74-7783-4bfb-a7ec-6eb87734a0a5)
