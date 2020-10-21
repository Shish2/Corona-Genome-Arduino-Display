// Simple LEDs, just cycling around
int minled=8;
int maxled=13;
int onled=minled;
int inc=1;

// Stuff to do with the color LED
int c=0;
int rgb[3] = {255, 99, 99};
int rpin=3;
int gpin=5;
int bpin=6;

// Stuff to do with the Potentiometer
int potpin = 5; // A5
int wtime = 50;

char genomeSeq[] = "1 cttcccaggt aacaaaccaa ccaactttcg atctcttgta gatctgttct ctaaacgaac"
       "61 tttaaaatct gtgtggctgt cactcggctg catgcttagt gcactcacgc agtataatta"
      "121 ataactaatt actgtcgttg acaggacacg agtaactcgt ctatcttctg caggctgctt"
      "181 acggtttcgt ccgtgttgca gccgatcatc agcacatcta ggtttcgtcc gggtgtgacc"
      "241 gaaaggtaag atggagagcc ttgtccctgg tttcaacgag aaaacacacg tccaactcag"
      "301 tttgcctgtt ttacaggttc gcgacgtgct cgtacgtggc tttggagact ccgtggagga"
      "361 ggtcttatca gaggcacgtc aacatcttaa agatggcact tgtggcttag tagaagttga"
      "421 aaaaggcgtt ttgcctcaac ttgaacagcc ctatgtgttc atcaaacgtt cggatgctcg"
      "481 aactgcacct catggtcatg ttatggttga gctggtagca gaactcgaag gcattcagta"
      "541 cggtcgtagt ggtgagacac ttggtgtcct tgtccctcat gtgggcgaaa taccagtggc"
      "601 ttaccgcaag gttcttcttc gtaagaacgg taataaagga gctggtggcc atagttacgg";
      /*
      "661 cgccgatcta aagtcatttg acttaggcga cgagcttggc actgatcctt atgaagattt"
      "721 tcaagaaaac tggaacacta aacatagcag tggtgttacc cgtgaactca tgcgtgagct"
      "781 taacggaggg gcatacactc gctatgtcga taacaacttc tgtggccctg atggctaccc"
      "841 tcttgagtgc attaaagacc ttctagcacg tgctggtaaa gcttcatgca ctttgtccga"
      "901 acaactggac tttattgaca ctaagagggg tgtatactgc tgccgtgaac atgagcatga"
      "961 aattgcttgg tacacggaac gttctgaaaa gagctatgaa ttgcagacac cttttgaaat"
     "1021 taaattggca aagaaatttg acaccttcaa tggggaatgt ccaaattttg tatttccctt"
     "1081 aaattccata atcaagacta ttcaaccaag ggttgaaaag aaaaagcttg atggctttat"
     "1141 gggtagaatt cgatctgtct atccagttgc gtcaccaaat gaatgcaacc aaatgtgcct"
     "1201 ttcaactctc atgaagtgtg atcattgtgg tgaaacttca tggcagacgg gcgattttgt"
     "1261 taaagccact tgcgaatttt gtggcactga gaatttgact aaagaaggtg ccactacttg"
     "1321 tggttactta ccccaaaatg ctgttgttaa aatttattgt ccagcatgtc acaattcaga"
     "1381 agtaggacct gagcatagtc ttgccgaata ccataatgaa tctggcttga aaaccattct"
     "1441 tcgtaagggt ggtcgcacta ttgcctttgg aggctgtgtg ttctcttatg ttggttgcca"
     "1501 taacaagtgt gcctattggg ttccacgtgc tagcgctaac ataggttgta accatacagg"
     "1561 tgttgttgga gaaggttccg aaggtcttaa tgacaacctt cttgaaatac tccaaaaaga"
     "1621 gaaagtcaac atcaatattg ttggtgactt taaacttaat gaagagatcg ccattatttt"
     "1681 ggcatctttt tctgcttcca caagtgcttt tgtggaaact gtgaaaggtt tggattataa"
     "1741 agcattcaaa caaattgttg aatcctgtgg taattttaaa gttacaaaag gaaaagctaa"
     "1801 aaaaggtgcc tggaatattg gtgaacagaa atcaatactg agtcctcttt atgcatttgc"
     "1861 atcagaggct gctcgtgttg tacgatcaat tttctcccgc actcttgaaa ctgctcaaaa"
     "1921 ttctgtgcgt gttttacaga aggccgctat aacaatacta gatggaattt cacagtattc"
     "1981 actgagactc attgatgcta tgatgttcac atctgatttg gctactaaca atctagttgt"
     "2041 aatggcctac attacaggtg gtgttgttca gttgacttcg cagtggctaa ctaacatctt"
     "2101 tggcactgtt tatgaaaaac tcaaacccgt ccttgattgg cttgaagaga agtttaagga"
     "2161 aggtgtagag tttcttagag acggttggga aattgttaaa tttatctcaa cctgtgcttg"
     "2221 tgaaattgtc ggtggacaaa ttgtcacctg tgcaaaggaa attaaggaga gtgttcagac"
     "2281 attctttaag cttgtaaata aatttttggc tttgtgtgct gactctatca ttattggtgg"
     "2341 agctaaactt aaagccttga atttaggtga aacatttgtc acgcactcaa agggattgta"
     "2401 cagaaagtgt gttaaatcca gagaagaaac tggcctactc atgcctctaa aagccccaaa"
     "2461 agaaattatc ttcttagagg gagaaacact tcccacagaa gtgttaacag aggaagttgt"
     "2521 cttgaaaact ggtgatttac aaccattaga acaacctact agtgaagctg ttgaagctcc"
     "2581 attggttggt acaccagttt gtattaacgg gcttatgttg ctcgaaatca aagacacaga"
     "2641 aaagtactgt gcccttgcac ctaatatgat ggtaacaaac aataccttca cactcaaagg"
     "2701 cggtgcacca acaaaggtta cttttggtga tgacactgtg atagaagtgc aaggttacaa"
     "2761 gagtgtgaat atcacttttg aacttgatga aaggattgat aaagtactta atgagaagtg"
     "2821 ctctgcctat acagttgaac tcggtacaga agtaaatgag ttcgcctgtg ttgtggcaga"
     "2881 tgctgtcata aaaactttgc aaccagtatc tgaattactt acaccactgg gcattgattt"
     "2941 agatgagtgg agtatggcta catactactt atttgatgag tctggtgagt ttaaattggc"
     "3001 ttcacatatg tattgttctt tctaccctcc agatgaggat gaagaagaag gtgattgtga"
     "3061 agaagaagag tttgagccat caactcaata tgagtatggt actgaagatg attaccaagg"
     "3121 taaacctttg gaatttggtg ccacttctgc tgctcttcaa cctgaagaag agcaagaaga"
     "3181 agattggtta gatgatgata gtcaacaaac tgttggtcaa caagacggca gtgaggacaa"
     "3241 tcagacaact actattcaaa caattgttga ggttcaacct caattagaga tggaacttac"
     "3301 accagttgtt cagactattg aagtgaatag ttttagtggt tatttaaaac ttactgacaa"
     "3361 tgtatacatt aaaaatgcag acattgtgga agaagctaaa aaggtaaaac caacagtggt"
     "3421 tgttaatgca gccaatgttt accttaaaca tggaggaggt gttgcaggag ccttaaataa"
     "3481 ggctactaac aatgccatgc aagttgaatc tgatgattac atagctacta atggaccact"
     "3541 taaagtgggt ggtagttgtg ttttaagcgg acacaatctt gctaaacact gtcttcatgt"
     "3601 tgtcggccca aatgttaaca aaggtgaaga cattcaactt cttaagagtg cttatgaaaa"
     "3661 ttttaatcag cacgaagttc tacttgcacc attattatca gctggtattt ttggtgctga"
     "3721 ccctatacat tctttaagag tttgtgtaga tactgttcgc acaaatgtct acttagctgt"
     "3781 ctttgataaa aatctctatg acaaacttgt ttcaagcttt ttggaaatga agagtgaaaa"
     "3841 gcaagttgaa caaaagatcg ctgagattcc taaagaggaa gttaagccat ttataactga"
     "3901 aagtaaacct tcagttgaac agagaaaaca agatgataag aaaatcaaag cttgtgttga"
     "3961 agaagttaca acaactctgg aagaaactaa gttcctcaca gaaaacttgt tactttatat"
     "4021 tgacattaat ggcaatcttc atccagattc tgccactctt gttagtgaca ttgacatcac"
     "4081 tttcttaaag aaagatgctc catatatagt gggtgatgtt gttcaagagg gtgttttaac"
     "4141 tgctgtggtt atacctacta aaaaggctgg tggcactact gaaatgctag cgaaagcttt"
     "4201 gagaaaagtg ccaacagaca attatataac cacttacccg ggtcagggtt taaatggtta"
     "4261 cactgtagag gaggcaaaga cagtgcttaa aaagtgtaaa agtgcctttt acattctacc"
     "4321 atctattatc tctaatgaga agcaagaaat tcttggaact gtttcttgga atttgcgaga"
     "4381 aatgcttgca catgcagaag aaacacgcaa attaatgcct gtctgtgtgg aaactaaagc"
     "4441 catagtttca actatacagc gtaaatataa gggtattaaa atacaagagg gtgtggttga"
     "4501 ttatggtgct agattttact tttacaccag taaaacaact gtagcgtcac ttatcaacac"
     "4561 acttaacgat ctaaatgaaa ctcttgttac aatgccactt ggctatgtaa cacatggctt"
     "4621 aaatttggaa gaagctgctc ggtatatgag atctctcaaa gtgccagcta cagtttctgt"
     "4681 ttcttcacct gatgctgtta cagcgtataa tggttatctt acttcttctt ctaaaacacc"
     "4741 tgaagaacat tttattgaaa ccatctcact tgctggttcc tataaagatt ggtcctattc"
     "4801 tggacaatct acacaactag gtatagaatt tcttaagaga ggtgataaaa gtgtatatta"
     "4861 cactagtaat cctaccacat tccacctaga tggtgaagtt atcacctttg acaatcttaa"
     "4921 gacacttctt tctttgagag aagtgaggac tattaaggtg tttacaacag tagacaacat"
     "4981 taacctccac acgcaagttg tggacatgtc aatgacatat ggacaacagt ttggtccaac"
     "5041 ttatttggat ggagctgatg ttactaaaat aaaacctcat aattcacatg aaggtaaaac"
     "5101 attttatgtt ttacctaatg atgacactct acgtgttgag gcttttgagt actaccacac"
     "5161 aactgatcct agttttctgg gtaggtacat gtcagcatta aatcacacta aaaagtggaa"
     "5221 atacccacaa gttaatggtt taacttctat taaatgggca gataacaact gttatcttgc"
     "5281 cactgcattg ttaacactcc aacaaataga gttgaagttt aatccacctg ctctacaaga"
     "5341 tgcttattac agagcaaggg ctggtgaagc tgctaacttt tgtgcactta tcttagccta"
     "5401 ctgtaataag acagtaggtg agttaggtga tgttagagaa acaatgagtt acttgtttca"
     "5461 acatgccaat ttagattctt gcaaaagagt cttgaacgtg gtgtgtaaaa cttgtggaca"
     "5521 acagcagaca acccttaagg gtgtagaagc tgttatgtac atgggcacac tttcttatga"
     "5581 acaatttaag aaaggtgttc agataccttg tacgtgtggt aaacaagcta caaaatatct"
     "5641 agtacaacag gagtcacctt ttgttatgat gtcagcacca cctgctcagt atgaacttaa"
     "5701 gcatggtaca tttacttgtg ctagtgagta cactggtaat taccagtgtg gtcactataa"
     "5761 acatataact tctaaagaaa ctttgtattg catagacggt gctttactta caaagtcctc"
     "5821 agaatacaaa ggtcctatta cggatgtttt ctacaaagaa aacagttaca caacaaccat"
     "5881 aaaaccagtt acttataaat tggatggtgt tgtttgtaca gaaattgacc ctaagttgga"
     "5941 caattattat aagaaagaca attcttattt cacagagcaa ccaattgatc ttgtaccaaa"
     "6001 ccaaccatat ccaaacgcaa gcttcgataa ttttaagttt gtatgtgata atatcaaatt"
     "6061 tgctgatgat ttaaaccagt taactggtta taagaaacct gcttcaagag agcttaaagt"
     "6121 tacatttttc cctgacttaa atggtgatgt ggtggctatt gattataaac actacacacc"
     "6181 ctcttttaag aaaggagcta aattgttaca taaacctatt gtttggcatg ttaacaatgc"
     "6241 aactaataaa gccacgtata aaccaaatac ctggtgtata cgttgtcttt ggagcacaaa"
     "6301 accagttgaa acatcaaatt cgtttgatgt actgaagtca gaggacgcgc agggaatgga"
     "6361 taatcttgcc tgcgaagatc taaaaccagt ctctgaagaa gtagtggaaa atcctaccat"
     "6421 acagaaagac gttcttgagt gtaatgtgaa aactaccgaa gttgtaggag acattatact"
     "6481 taaaccagca aataatagtt taaaaattac agaagaggtt ggccacacag atctaatggc"
     "6541 tgcttatgta gacaattcta gtcttactat taagaaacct aatgaattat ctagagtatt"
     "6601 aggtttgaaa acccttgcta ctcatggttt agctgctgtt aatagtgtcc cttgggatac"
     "6661 tatagctaat tatgctaagc cttttcttaa caaagttgtt agtacaacta ctaacatagt"
     "6721 tacacggtgt ttaaaccgtg tttgtactaa ttatatgcct tatttcttta ctttattgct"
     "6781 acaattgtgt acttttacta gaagtacaaa ttctagaatt aaagcatcta tgccgactac"
     "6841 tatagcaaag aatactgtta agagtgtcgg taaattttgt ctagaggctt catttaatta"
     "6901 tttgaagtca cctaattttt ctaaactgat aaatattata atttggtttt tactattaag"
     "6961 tgtttgccta ggttctttaa tctactcaac cgctgcttta ggtgttttaa tgtctaattt"
     "7021 aggcatgcct tcttactgta ctggttacag agaaggctat ttgaactcta ctaatgtcac"
     "7081 tattgcaacc tactgtactg gttctatacc ttgtagtgtt tgtcttagtg gtttagattc"
     "7141 tttagacacc tatccttctt tagaaactat acaaattacc atttcatctt ttaaatggga"
     "7201 tttaactgct tttggcttag ttgcagagtg gtttttggca tatattcttt tcactaggtt"
     "7261 tttctatgta cttggattgg ctgcaatcat gcaattgttt ttcagctatt ttgcagtaca"
     "7321 ttttattagt aattcttggc ttatgtggtt aataattaat cttgtacaaa tggccccgat"
     "7381 ttcagctatg gttagaatgt acatcttctt tgcatcattt tattatgtat ggaaaagtta"
     "7441 tgtgcatgtt gtagacggtt gtaattcatc aacttgtatg atgtgttaca aacgtaatag"
     "7501 agcaacaaga gtcgaatgta caactattgt taatggtgtt agaaggtcct tttatgtcta"
     "7561 tgctaatgga ggtaaaggct tttgcaaact acacaattgg aattgtgtta attgtgatac"
     "7621 attctgtgct ggtagtacat ttattagtga tgaagttgcg agagacttgt cactacagtt"
     "7681 taaaagacca ataaatccta ctgaccagtc ttcttacatc gttgatagtg ttacagtgaa"
     "7741 gaatggttcc atccatcttt actttgataa agctggtcaa aagacttatg aaagacattc"
     "7801 tctctctcat tttgttaact tagacaacct gagagctaat aacactaaag gttcattgcc"
     "7861 tattaatgtt atagtttttg atggtaaatc aaaatgtgaa gaatcatctg caaaatcagc"
     "7921 gtctgtttac tacagtcagc ttatgtgtca acctatactg ttactagatc aggcattagt"
     "7981 gtctgatgtt ggtgatagtg cggaagttgc agttaaaatg tttgatgctt acgttaatac"
     "8041 gttttcatca acttttaacg taccaatgga aaaactcaaa acactagttg caactgcaga"
     "8101 agctgaactt gcaaagaatg tgtccttaga caatgtctta tctactttta tttcagcagc"
     "8161 tcggcaaggg tttgttgatt cagatgtaga aactaaagat gttgttgaat gtcttaaatt"
     "8221 gtcacatcaa tctgacatag aagttactgg cgatagttgt aataactata tgctcaccta"
     "8281 taacaaagtt gaaaacatga caccccgtga ccttggtgct tgtattgact gtagtgcgcg"
     "8341 tcatattaat gcgcaggtag caaaaagtca caacattgct ttgatatgga acgttaaaga"
     "8401 tttcatgtca ttgtctgaac aactacgaaa acaaatacgt agtgctgcta aaaagaataa"
     "8461 cttacctttt aagttgacat gtgcaactac tagacaagtt gttaatgttg taacaacaaa"
     "8521 gatagcactt aagggtggta aaattgttaa taattggttg aagcagttaa ttaaagttac"
     "8581 acttgtgttc ctttttgttg ctgctatttt ctatttaata acacctgttc atgtcatgtc"
     "8641 taaacatact gacttttcaa gtgaaatcat aggatacaag gctattgatg gtggtgtcac"
     "8701 tcgtgacata gcatctacag atacttgttt tgctaacaaa catgctgatt ttgacacatg"
     "8761 gtttagccag cgtggtggta gttatactaa tgacaaagct tgcccattga ttgctgcagt"
     "8821 cataacaaga gaagtgggtt ttgtcgtgcc tggtttgcct ggcacgatat tacgcacaac"
     "8881 taatggtgac tttttgcatt tcttacctag agtttttagt gcagttggta acatctgtta"
     "8941 cacaccatca aaacttatag agtacactga ctttgcaaca tcagcttgtg ttttggctgc"
     "9001 tgaatgtaca atttttaaag atgcttctgg taagccagta ccatattgtt atgataccaa"
     "9061 tgtactagaa ggttctgttg cttatgaaag tttacgccct gacacacgtt atgtgctcat"
     "9121 ggatggctct attattcaat ttcctaacac ctaccttgaa ggttctgtta gagtggtaac"
     "9181 aacttttgat tctgagtact gtaggcacgg cacttgtgaa agatcagaag ctggtgtttg"
     "9241 tgtatctact agtggtagat gggtacttaa caatgattat tacagatctt taccaggagt"
     "9301 tttctgtggt gtagatgctg taaatttact tactaatatg tttacaccac taattcaacc"
     "9361 tattggtgct ttggacatat cagcatctat agtagctggt ggtattgtag ctatcgtagt"
     "9421 aacatgcctt gcctactatt ttatgaggtt tagaagagct tttggtgaat acagtcatgt"
     "9481 agttgccttt aatactttac tattccttat gtcattcact gtactctgtt taacaccagt"
     "9541 ttactcattc ttacctggtg tttattctgt tatttacttg tacttgacat tttatcttac"
     "9601 taatgatgtt tcttttttag cacatattca gtggatggtt atgttcacac ctttagtacc"
     "9661 tttctggata acaattgctt atatcatttg tatttccaca aagcatttct attggttctt"
     "9721 tagtaattac ctaaagagac gtgtagtctt taatggtgtt tcctttagta cttttgaaga"
     "9781 agctgcgctg tgcacctttt tgttaaataa agaaatgtat ctaaagttgc gtagtgatgt"
     "9841 gctattacct cttacgcaat ataatagata cttagctctt tataataagt acaagtattt"
     "9901 tagtggagca atggatacaa ctagctacag agaagctgct tgttgtcatc tcgcaaaggc"
     "9961 tctcaatgac ttcagtaact caggttctga tgttctttac caaccaccac aaacctctat"
    "10021 cacctcagct gttttgcaga gtggttttag aaaaatggca ttcccatctg gtaaagttga"
    "10081 gggttgtatg gtacaagtaa cttgtggtac aactacactt aacggtcttt ggcttgatga"
    "10141 cgtagtttac tgtccaagac atgtgatctg cacctctgaa gacatgctta accctaatta"
    "10201 tgaagattta ctcattcgta agtctaatca taatttcttg gtacaggctg gtaatgttca"
    "10261 actcagggtt attggacatt ctatgcaaaa ttgtgtactt aagcttaagg ttgatacagc"
    "10321 caatcctaag acacctaagt ataagtttgt tcgcattcaa ccaggacaga ctttttcagt"
    "10381 gttagcttgt tacaatggtt caccatctgg tgtttaccaa tgtgctatga ggcccaattt"
    "10441 cactattaag ggttcattcc ttaatggttc atgtggtagt gttggtttta acatagatta"
    "10501 tgactgtgtc tctttttgtt acatgcacca tatggaatta ccaactggag ttcatgctgg"
    "10561 cacagactta gaaggtaact tttatggacc ttttgttgac aggcaaacag cacaagcagc"
    "10621 tggtacggac acaactatta cagttaatgt tttagcttgg ttgtacgctg ctgttataaa"
    "10681 tggagacagg tggtttctca atcgatttac cacaactctt aatgacttta accttgtggc"
    "10741 tatgaagtac aattatgaac ctctaacaca agaccatgtt gacatactag gacctctttc"
    "10801 tgctcaaact ggaattgccg ttttagatat gtgtgcttca ttaaaagaat tactgcaaaa"
    "10861 tggtatgaat ggacgtacca tattgggtag tgctttatta gaagatgaat ttacaccttt"
    "10921 tgatgttgtt agacaatgct caggtgttac tttccaaagt gcagtgaaaa gaacaatcaa"
    "10981 gggtacacac cactggttgt tactcacaat tttgacttca cttttagttt tagtccagag"
    "11041 tactcaatgg tctttgttct tttttttgta tgaaaatgcc tttttacctt ttgctatggg"
    "11101 tattattgct atgtctgctt ttgcaatgat gtttgtcaaa cataagcatg catttctctg"
    "11161 tttgtttttg ttaccttctc ttgccactgt agcttatttt aatatggtct atatgcctgc"
    "11221 tagttgggtg atgcgtatta tgacatggtt ggatatggtt gatactagtt tgtctggttt"
    "11281 taagctaaaa gactgtgtta tgtatgcatc agctgtagtg ttactaatcc ttatgacagc"
    "11341 aagaactgtg tatgatgatg gtgctaggag agtgtggaca cttatgaatg tcttgacact"
    "11401 cgtttataaa gtttattatg gtaatgcttt agatcaagcc atttccatgt gggctcttat"
    "11461 aatctctgtt acttctaact actcaggtgt agttacaact gtcatgtttt tggccagagg"
    "11521 tattgttttt atgtgtgttg agtattgccc tattttcttc ataactggta atacacttca"
    "11581 gtgtataatg ctagtttatt gtttcttagg ctatttttgt acttgttact ttggcctctt"
    "11641 ttgtttactc aaccgctact ttagactgac tcttggtgtt tatgattact tagtttctac"
    "11701 acaggagttt agatatatga attcacaggg actactccca cccaagaata gcatagatgc"
    "11761 cttcaaactc aacattaaat tgttgggtgt tggtggcaaa ccttgtatca aagtagccac"
    "11821 tgtacagtct aaaatgtcag atgtaaagtg cacatcagta gtcttactct cagttttgca"
    "11881 acaactcaga gtagaatcat catctaaatt gtgggctcaa tgtgtccagt tacacaatga"
    "11941 cattctctta gctaaagata ctactgaagc ctttgaaaaa atggtttcac tactttctgt"
    "12001 tttgctttcc atgcagggtg ctgtagacat aaacaagctt tgtgaagaaa tgctggacaa"
    "12061 cagggcaacc ttacaagcta tagcctcaga gtttagttcc cttccatcat atgcagcttt"
    "12121 tgctactgct caagaagctt atgagcaggc tgttgctaat ggtgattctg aagttgttct"
    "12181 taaaaagttg aagaagtctt tgaatgtggc taaatctgaa tttgaccgtg atgcagccat"
    "12241 gcaacgtaag ttggaaaaga tggctgatca agctatgacc caaatgtata aacaggctag"
    "12301 atctgaggac aagagggcaa aagttactag tgctatgcag acaatgcttt tcactatgct"
    "12361 tagaaagttg gataatgatg cactcaacaa cattatcaac aatgcaagag atggttgtgt"
    "12421 tcccttgaac ataatacctc ttacaacagc agccaaacta atggttgtca taccagacta"
    "12481 taacacatat aaaaatacgt gtgatggtac aacatttact tatgcatcag cattgtggga"
    "12541 aatccaacag gttgtagatg cagatagtaa aattgttcaa cttagtgaaa ttagtatgga"
    "12601 caattcacct aatttagcat ggcctcttat tgtaacagct ttaagggcca attctgctgt"
    "12661 caaattacag aataatgagc ttagtcctgt tgcactacga cagatgtctt gtgctgccgg"
    "12721 tactacacaa actgcttgca ctgatgacaa tgcgttagct tactacaaca caacaaaggg"
    "12781 aggtaggttt gtacttgcac tgttatccga tttacaggat ttgaaatggg ctagattccc"
    "12841 taagagtgat ggaactggta ctatctatac agaactggaa ccaccttgta ggtttgttac"
    "12901 agacacacct aaaggtccta aagtgaagta tttatacttt attaaaggat taaacaacct"
    "12961 aaatagaggt atggtacttg gtagtttagc tgccacagta cgtctacaag ctggtaatgc"
    "13021 aacagaagtg cctgccaatt caactgtatt atctttctgt gcttttgctg tagatgctgc"
    "13081 taaagcttac aaagattatc tagctagtgg gggacaacca atcactaatt gtgttaagat"
    "13141 gttgtgtaca cacactggta ctggtcaggc aataacagtt acaccggaag ccaatatgga"
    "13201 tcaagaatcc tttggtggtg catcgtgttg tctgtactgc cgttgccaca tagatcatcc"
    "13261 aaatcctaaa ggattttgtg acttaaaagg taagtatgta caaataccta caacttgtgc"
    "13321 taatgaccct gtgggtttta cacttaaaaa cacagtctgt accgtctgcg gtatgtggaa"
    "13381 aggttatggc tgtagttgtg atcaactccg cgaacccatg cttcagtcag ctgatgcaca"
    "13441 atcgttttta aacgggtttg cggtgtaagt gcagcccgtc ttacaccgtg cggcacaggc"
    "13501 actagtactg atgtcgtata cagggctttt gacatctaca atgataaagt agctggtttt"
    "13561 gctaaattcc taaaaactaa ttgttgtcgc ttccaagaaa aggacgaaga tgacaattta"
    "13621 attgattctt actttgtagt taagagacac actttctcta actaccaaca tgaagaaaca"
    "13681 atttataatt tacttaagga ttgtccagct gttgctaaac atgacttctt taagtttaga"
    "13741 atagacggtg acatggtacc acatatatca cgtcaacgtc ttactaaata cacaatggca"
    "13801 gacctcgtct atgctttaag gcattttgat gaaggtaatt gtgacacatt aaaagaaata"
    "13861 cttgtcacat acaattgttg tgatgatgat tatttcaata aaaaggactg gtatgatttt"
    "13921 gtagaaaacc cagatatatt acgcgtatac gccaacttag gtgaacgtgt acgccaagct"
    "13981 ttgttaaaaa cagtacaatt ctgtgatgcc atgcgaaatg ctggtattgt tggtgtactg"
    "14041 acattagata atcaagatct caatggtaac tggtatgatt tcggtgattt catacaaacc"
    "14101 acgccaggta gtggagttcc tgttgtagat tcttattatt cattgttaat gcctatatta"
    "14161 accttgacca gggctttaac tgcagagtca catgttgaca ctgacttaac aaagccttac"
    "14221 attaagtggg atttgttaaa atatgacttc acggaagaga ggttaaaact ctttgaccgt"
    "14281 tattttaaat attgggatca gacataccac ccaaattgtg ttaactgttt ggatgacaga"
    "14341 tgcattctgc attgtgcaaa ctttaatgtt ttattctcta cagtgttccc acctacaagt"
    "14401 tttggaccac tagtgagaaa aatatttgtt gatggtgttc catttgtagt ttcaactgga"
    "14461 taccacttca gagagctagg tgttgtacat aatcaggatg taaacttaca tagctctaga"
    "14521 cttagtttta aggaattact tgtgtatgct gctgaccctg ctatgcacgc tgcttctggt"
    "14581 aatctattac tagataaacg cactacgtgc ttttcagtag ctgcacttac taacaatgtt"
    "14641 gcttttcaaa ctgtcaaacc cggtaatttt aacaaagact tctatgactt tgctgtgtct"
    "14701 aagggtttct ttaaggaagg aagttctgtt gaattaaaac acttcttctt tgctcaggat"
    "14761 ggtaatgctg ctatcagcga ttatgactac tatcgttata atctaccaac aatgtgtgat"
    "14821 atcagacaac tactatttgt agttgaagtt gttgataagt actttgattg ttacgatggt"
    "14881 ggctgtatta atgctaacca agtcatcgtc aacaacctag acaaatcagc tggttttcca"
    "14941 tttaataaat ggggtaaggc tagactttat tatgattcaa tgagttatga ggatcaagat"
    "15001 gcacttttcg catatacaaa acgtaatgtc atccctacta taactcaaat gaatcttaag"
    "15061 tatgccatta gtgcaaagaa tagagctcgc accgtagctg gtgtctctat ctgtagtact"
    "15121 atgaccaata gacagtttca tcaaaaatta ttgaaatcaa tagccgccac tagaggagct"
    "15181 actgtagtaa ttggaacaag caaattctat ggtggttggc acaacatgtt aaaaactgtt"
    "15241 tatagtgatg tagaaaaccc tcaccttatg ggttgggatt atcctaaatg tgatagagcc"
    "15301 atgcctaaca tgcttagaat tatggcctca cttgttcttg ctcgcaaaca tacaacgtgt"
    "15361 tgtagcttgt cacaccgttt ctatagatta gctaatgagt gtgctcaagt attgagtgaa"
    "15421 atggtcatgt gtggcggttc actatatgtt aaaccaggtg gaacctcatc aggagatgcc"
    "15481 acaactgctt atgctaatag tgtttttaac atttgtcaag ctgtcacggc caatgttaat"
    "15541 gcacttttat ctactgatgg taacaaaatt gccgataagt atgtccgcaa tttacaacac"
    "15601 agactttatg agtgtctcta tagaaataga gatgttgaca cagactttgt gaatgagttt"
    "15661 tacgcatatt tgcgtaaaca tttctcaatg atgatactct ctgacgatgc tgttgtgtgt"
    "15721 ttcaatagca cttatgcatc tcaaggtcta gtggctagca taaagaactt taagtcagtt"
    "15781 ctttattatc aaaacaatgt ttttatgtct gaagcaaaat gttggactga gactgacctt"
    "15841 actaaaggac ctcatgaatt ttgctctcaa catacaatgc tagttaaaca gggtgatgat"
    "15901 tatgtgtacc ttccttaccc agatccatca agaatcctag gggccggctg ttttgtagat"
    "15961 gatatcgtaa aaacagatgg tacacttatg attgaacggt tcgtgtcttt agctatagat"
    "16021 gcttacccac ttactaaaca tcctaatcag gagtatgctg atgtctttca tttgtactta"
    "16081 caatacataa gaaagctaca tgatgagtta acaggacaca tgttagacat gtattctgtt"
    "16141 atgcttacta atgataacac ttcaaggtat tgggaacctg agttttatga ggctatgtac"
    "16201 acaccgcata cagtcttaca ggctgttggg gcttgtgttc tttgcaattc acagacttca"
    "16261 ttaagatgtg gtgcttgcat acgtagacca ttcttatgtt gtaaatgctg ttacgaccat"
    "16321 gtcatatcaa catcacataa attagtcttg tctgttaatc cgtatgtttg caatgctcca"
    "16381 ggttgtgatg tcacagatgt gactcaactt tacttaggag gtatgagcta ttattgtaaa"
    "16441 tcacataaac cacccattag ttttccattg tgtgctaatg gacaagtttt tggtttatat"
    "16501 aaaaatacat gtgttggtag cgataatgtt actgacttta atgcaattgc aacatgtgac"
    "16561 tggacaaatg ctggtgatta cattttagct aacacctgta ctgaaagact caagcttttt"
    "16621 gcagcagaaa cgctcaaagc tactgaggag acatttaaac tgtcttatgg tattgctact"
    "16681 gtacgtgaag tgctgtctga cagagaatta catctttcat gggaagttgg taaacctaga"
    "16741 ccaccactta accgaaatta tgtctttact ggttatcgtg taactaaaaa cagtaaagta"
    "16801 caaataggag agtacacctt tgaaaaaggt gactatggtg atgctgttgt ttaccgaggt"
    "16861 acaacaactt acaaattaaa tgttggtgat tattttgtgc tgacatcaca tacagtaatg"
    "16921 ccattaagtg cacctacact agtgccacaa gagcactatg ttagaattac tggcttatac"
    "16981 ccaacactca atatctcaga tgagttttct agcaatgttg caaattatca aaaggttggt"
    "17041 atgcaaaagt attctacact ccagggacca cctggtactg gtaagagtca ttttgctatt"
    "17101 ggcctagctc tctactaccc ttctgctcgc atagtgtata cagcttgctc tcatgccgct"
    "17161 gttgatgcac tatgtgagaa ggcattaaaa tatttgccta tagataaatg tagtagaatt"
    "17221 atacctgcac gtgctcgtgt agagtgtttt gataaattca aagtgaattc aacattagaa"
    "17281 cagtatgtct tttgtactgt aaatgcattg cctgagacga cagcagatat agttgtcttt"
    "17341 gatgaaattt caatggccac aaattatgat ttgagtgttg tcaatgccag attacgtgct"
    "17401 aagcactatg tgtacattgg cgaccctgct caattacctg caccacgcac attgctaact"
    "17461 aagggcacac tagaaccaga atatttcaat tcagtgtgta gacttatgaa aactataggt"
    "17521 ccagacatgt tcctcggaac ttgtcggcgt tgtcctgctg aaattgttga cactgtgagt"
    "17581 gctttggttt atgataataa gcttaaagca cataaagaca aatcagctca atgctttaaa"
    "17641 atgttttata agggtgttat cacgcatgat gtttcatctg caattaacag gccacaaata"
    "17701 ggcgtggtaa gagaattcct tacacgtaac cctgcttgga gaaaagctgt ctttatttca"
    "17761 ccttataatt cacagaatgc tgtagcctca aagattttgg gactaccaac tcaaactgtt"
    "17821 gattcatcac agggctcaga atatgactat gtcatattca ctcaaaccac tgaaacagct"
    "17881 cactcttgta atgtaaacag atttaatgtt gctattacca gagcaaaagt aggcatactt"
    "17941 tgcataatgt ctgatagaga cctttatgac aagttgcaat ttacaagtct tgaaattcca"
    "18001 cgtaggaatg tggcaacttt acaagctgaa aatgtaacag gactctttaa agattgtagt"
    "18061 aaggtaatca ctgggttaca tcctacacag gcacctacac acctcagtgt tgacactaaa"
    "18121 ttcaaaactg aaggtttatg tgttgacata cctggcatac ctaaggacat gacctataga"
    "18181 agactcatct ctatgatggg ttttaaaatg aattatcaag ttaatggtta ccctaacatg"
    "18241 tttatcaccc gcgaagaagc tataagacat gtacgtgcat ggattggctt cgatgtcgag"
    "18301 gggtgtcatg ctactagaga agctgttggt accaatttac ctttacagct aggtttttct"
    "18361 acaggtgtta acctagttgc tgtacctaca ggttatgttg atacacctaa taatacagat"
    "18421 ttttccagag ttagtgctaa accaccgcct ggagatcaat ttaaacacct cataccactt"
    "18481 atgtacaaag gacttccttg gaatgtagtg cgtataaaga ttgtacaaat gttaagtgac"
    "18541 acacttaaaa atctctctga cagagtcgta tttgtcttat gggcacatgg ctttgagttg"
    "18601 acatctatga agtattttgt gaaaatagga cctgagcgca cctgttgtct atgtgataga"
    "18661 cgtgccacat gcttttccac tgcttcagac acttatgcct gttggcatca ttctattgga"
    "18721 tttgattacg tctataatcc gtttatgatt gatgttcaac aatggggttt tacaggtaac"
    "18781 ctacaaagca accatgatct gtattgtcaa gtccatggta atgcacatgt agctagttgt"
    "18841 gatgcaatca tgactaggtg tctagctgtc cacgagtgct ttgttaagcg tgttgactgg"
    "18901 actattgaat atcctataat tggtgatgaa ctgaagatta atgcggcttg tagaaaggtt"
    "18961 caacacatgg ttgttaaagc tgcattatta gcagacaaat tcccagttct tcacgacatt"
    "19021 ggtaacccta aagctattaa gtgtgtacct caagctgatg tagaatggaa gttctatgat"
    "19081 gcacagcctt gtagtgacaa agcttataaa atagaagaat tattctattc ttatgccaca"
    "19141 cattctgaca aattcacaga tggtgtatgc ctattttgga attgcaatgt cgatagatat"
    "19201 cctgctaatt ccattgtttg tagatttgac actagagtgc tatctaacct taacttgcct"
    "19261 ggttgtgatg gtggcagttt gtatgtaaat aaacatgcat tccacacacc agcttttgat"
    "19321 aaaagtgctt ttgttaattt aaaacaatta ccatttttct attactctga cagtccatgt"
    "19381 gagtctcatg gaaaacaagt agtgtcagat atagattatg taccactaaa gtctgctacg"
    "19441 tgtataacac gttgcaattt aggtggtgct gtctgtagac atcatgctaa tgagtacaga"
    "19501 ttgtatctcg atgcttataa catgatgatc tcagctggct ttagcttgtg ggtttacaaa"
    "19561 caatttgata cttataacct ctggaacact tttacaagac ttcagagttt agaaaatgtg"
    "19621 gcttttaatg ttgtaaataa gggacacttt gatggacaac agggtgaagt accagtttct"
    "19681 atcattaata acactgttta cacaaaagtt gatggtgttg atgtagaatt gtttgaaaat"
    "19741 aaaacaacat tacctgttaa tgtagcattt gagctttggg ctaagcgcaa cattaaacca"
    "19801 gtaccagagg tgaaaatact caataatttg ggtgtggaca ttgctgctaa tactgtgatc"
    "19861 tgggactaca aaagagatgc tccagcacat atatctacta ttggtgtttg ttctatgact"
    "19921 gacatagcca agaaaccaac tgaaacgatt tgtgcaccac tcactgtctt ttttgatggt"
    "19981 agagttgatg gtcaagtaga cttatttaga aatgcccgta atggtgttct tattacagaa"
    "20041 ggtagtgtta aaggtttaca accatctgta ggtcccaaac aagctagtct taatggagtc"
    "20101 acattaattg gagaagccgt aaaaacacag ttcaattatt ataagaaagt tgatggtgtt"
    "20161 gtccaacaat tacctgaaac ttactttact cagagtagaa atttacaaga atttaaaccc"
    "20221 aggagtcaaa tggaaattga tttcttagaa ttagctatgg atgaattcat tgaacggtat"
    "20281 aaattagaag gctatgcctt cgaacatatc gtttatggag attttagtca tagtcagtta"
    "20341 ggtggtttac atctactgat tggactagct aaacgtttta aggaatcacc ttttgaatta"
    "20401 gaagatttta ttcctatgga cagtacagtt aaaaactatt tcataacaga tgcgcaaaca"
    "20461 ggttcatcta agtgtgtgtg ttctgttatt gatttattac ttgatgattt tgttgaaata"
    "20521 ataaaatccc aagatttatc tgtagtttct aaggttgtca aagtgactat tgactataca"
    "20581 gaaatttcat ttatgctttg gtgtaaagat ggccatgtag aaacatttta cccaaaatta"
    "20641 caatctagtc aagcgtggca accgggtgtt gctatgccta atctttacaa aatgcaaaga"
    "20701 atgctattag aaaagtgtga ccttcaaaat tatggtgata gtgcaacatt acctaaaggc"
    "20761 ataatgatga atgtcgcaaa atatactcaa ctgtgtcaat atttaaacac attaacatta"
    "20821 gctgtaccct ataatatgag agttatacat tttggtgctg gttctgataa aggagttgca"
    "20881 ccaggtacag ctgttttaag acagtggttg cctacgggta cgctgcttgt cgattcagat"
    "20941 cttaatgact ttgtctctga tgcagattca actttgattg gtgattgtgc aactgtacat"
    "21001 acagctaata aatgggatct cattattagt gatatgtacg accctaagac taaaaatgtt"
    "21061 acaaaagaaa atgactctaa agagggtttt ttcacttaca tttgtgggtt tatacaacaa"
    "21121 aagctagctc ttggaggttc cgtggctata aagataacag aacattcttg gaatgctgat"
    "21181 ctttataagc tcatgggaca cttcgcatgg tggacagcct ttgttactaa tgtgaatgcg"
    "21241 tcatcatctg aagcattttt aattggatgt aattatcttg gcaaaccacg cgaacaaata"
    "21301 gatggttatg tcatgcatgc aaattacata ttttggagga atacaaatcc aattcagttg"
    "21361 tcttcctatt ctttatttga catgagtaaa tttcccctta aattaagggg tactgctgtt"
    "21421 atgtctttaa aagaaggtca aatcaatgat atgattttat ctcttcttag taaaggtaga"
    "21481 cttataatta gagaaaacaa cagagttgtt atttctagtg atgttcttgt taacaactaa"
    "21541 acgaacaatg tttgtttttc ttgttttatt gccactagtc tctagtcagt gtgttaatct"
    "21601 tacaaccaga actcaattac cccctgcata cactaattct ttcacacgtg gtgtttatta"
    "21661 ccctgacaaa gttttcagat cctcagtttt acattcaact caggacttgt tcttaccttt"
    "21721 cttttccaat gttacttggt tccatgctat acatgtctct gggaccaatg gtactaagag"
    "21781 gtttgataac cctgtcctac catttaatga tggtgtttat tttgcttcca ctgagaagtc"
    "21841 taacataata agaggctgga tttttggtac tactttagat tcgaagaccc agtccctact"
    "21901 tattgttaat aacgctacta atgttgttat taaagtctgt gaatttcaat tttgtaatga"
    "21961 tccatttttg ggtgtttatt accacaaaaa caacaaaagt tggatggaaa gtgagttcag"
    "22021 agtttattct agtgcgaata attgcacttt tgaatatgtc tctcagcctt ttcttatgga"
    "22081 ccttgaagga aaacagggta atttcaaaaa tcttagggaa tttgtgttta agaatattga"
    "22141 tggttatttt aaaatatatt ctaagcacac gcctattaat ttagtgcgtg atctccctca"
    "22201 gggtttttcg gctttagaac cattggtaga tttgccaata ggtattaaca tcactaggtt"
    "22261 tcaaacttta cttgctttac atagaagtta tttgactcct ggtgattctt cttcaggttg"
    "22321 gacagctggt gctgcagctt attatgtggg ttatcttcaa cctaggactt ttctattaaa"
    "22381 atataatgaa aatggaacca ttacagatgc tgtagactgt gcacttgacc ctctctcaga"
    "22441 aacaaagtgt acgttgaaat ccttcactgt agaaaaagga atctatcaaa cttctaactt"
    "22501 tagagtccaa ccaacagaat ctattgttag atttcctaat attacaaact tgtgcccttt"
    "22561 tggtgaagtt tttaacgcca ccagatttgc atctgtttat gcttggaaca ggaagagaat"
    "22621 cagcaactgt gttgctgatt attctgtcct atataattcc gcatcatttt ccacttttaa"
    "22681 gtgttatgga gtgtctccta ctaaattaaa tgatctctgc tttactaatg tctatgcaga"
    "22741 ttcatttgta attagaggtg atgaagtcag acaaatcgct ccagggcaaa ctggaaagat"
    "22801 tgctgattat aattataaat taccagatga ttttacaggc tgcgttatag cttggaattc"
    "22861 taacaatctt gattctaagg ttggtggtaa ttataattac ctgtatagat tgtttaggaa"
    "22921 gtctaatctc aaaccttttg agagagatat ttcaactgaa atctatcagg ccggtagcac"
    "22981 accttgtaat ggtgttgaag gttttaattg ttactttcct ttacaatcat atggtttcca"
    "23041 acccactaat ggtgttggtt accaaccata cagagtagta gtactttctt ttgaacttct"
    "23101 acatgcacca gcaactgttt gtggacctaa aaagtctact aatttggtta aaaacaaatg"
    "23161 tgtcaatttc aacttcaatg gtttaacagg cacaggtgtt cttactgagt ctaacaaaaa"
    "23221 gtttctgcct ttccaacaat ttggcagaga cattgctgac actactgatg ctgtccgtga"
    "23281 tccacagaca cttgagattc ttgacattac accatgttct tttggtggtg tcagtgttat"
    "23341 aacaccagga acaaatactt ctaaccaggt tgctgttctt tatcaggatg ttaactgcac"
    "23401 agaagtccct gttgctattc atgcagatca acttactcct acttggcgtg tttattctac"
    "23461 aggttctaat gtttttcaaa cacgtgcagg ctgtttaata ggggctgaac atgtcaacaa"
    "23521 ctcatatgag tgtgacatac ccattggtgc aggtatatgc gctagttatc agactcagac"
    "23581 taattctcct cggcgggcac gtagtgtagc tagtcaatcc atcattgcct acactatgtc"
    "23641 acttggtgca gaaaattcag ttgcttactc taataactct attgccatac ccacaaattt"
    "23701 tactattagt gttaccacag aaattctacc agtgtctatg accaagacat cagtagattg"
    "23761 tacaatgtac atttgtggtg attcaactga atgcagcaat cttttgttgc aatatggcag"
    "23821 tttttgtaca caattaaacc gtgctttaac tggaatagct gttgaacaag acaaaaacac"
    "23881 ccaagaagtt tttgcacaag tcaaacaaat ttacaaaaca ccaccaatta aagattttgg"
    "23941 tggttttaat ttttcacaaa tattaccaga tccatcaaaa ccaagcaaga ggtcatttat"
    "24001 tgaagatcta cttttcaata aagtgacact tgcagatgct ggcttcatca aacaatatgg"
    "24061 tgattgcctt ggtgatattg ctgctagaga cctcatttgt gcacaaaagt ttaacggcct"
    "24121 tactgttttg ccacctttgc tcacagatga aatgattgct caatacactt ctgcactgtt"
    "24181 agcgggtaca atcacttctg gttggacctt tggtgcaggt gctgcattac aaataccatt"
    "24241 tgctatgcaa atggcttata ggtttaatgg tattggagtt acacagaatg ttctctatga"
    "24301 gaaccaaaaa ttgattgcca accaatttaa tagtgctatt ggcaaaattc aagactcact"
    "24361 ttcttccaca gcaagtgcac ttggaaaact tcaagatgtg gtcaaccaaa atgcacaagc"
    "24421 tttaaacacg cttgttaaac aacttagctc caattttggt gcaatttcaa gtgttttaaa"
    "24481 tgatatcctt tcacgtcttg acaaagttga ggctgaagtg caaattgata ggttgatcac"
    "24541 aggcagactt caaagtttgc agacatatgt gactcaacaa ttaattagag ctgcagaaat"
    "24601 cagagcttct gctaatcttg ctgctactaa aatgtcagag tgtgtacttg gacaatcaaa"
    "24661 aagagttgat ttttgtggaa agggctatca tcttatgtcc ttccctcagt cagcacctca"
    "24721 tggtgtagtc ttcttgcatg tgacttatgt ccctgcacaa gaaaagaact tcacaactgc"
    "24781 tcctgccatt tgtcatgatg gaaaagcaca ctttcctcgt gaaggtgtct ttgtttcaaa"
    "24841 tggcacacac tggtttgtaa cacaaaggaa tttttatgaa ccacaaatca ttactacaga"
    "24901 caacacattt gtgtctggta actgtgatgt tgtaatagga attgtcaaca acacagttta"
    "24961 tgatcctttg caacctgaat tagactcatt caaggaggag ttagataaat attttaagaa"
    "25021 tcatacatca ccagatgttg atttaggtga catctctggc attaatgctt cagttgtaaa"
    "25081 cattcaaaaa gaaattgacc gcctcaatga ggttgccaag aatttaaatg aatctctcat"
    "25141 cgatctccaa gaacttggaa agtatgagca gtatataaaa tggccatggt acatttggct"
    "25201 aggttttata gctggcttga ttgccatagt aatggtgaca attatgcttt gctgtatgac"
    "25261 cagttgctgt agttgtctca agggctgttg ttcttgtgga tcctgctgca aatttgatga"
    "25321 agacgactct gagccagtgc tcaaaggagt caaattacat tacacataaa cgaacttatg"
    "25381 gatttgttta tgagaatctt cacaattgga actgtaactt tgaagcaagg tgaaatcaag"
    "25441 gatgctactc cttcagattt tgttcgcgct actgcaacga taccgataca agcctcactc"
    "25501 cctttcggat ggcttattgt tggcgttgca cttcttgctg tttttcagag cgcttccaaa"
    "25561 atcataaccc tcaaaaagag atggcaacta gcactctcca agggtgttca ctttgtttgc"
    "25621 aacttgctgt tgttgtttgt aacagtttac tcacaccttt tgctcgttgc tgctggcctt"
    "25681 gaagcccctt ttctctatct ttatgcttta gtctacttct tgcagagtat aaactttgta"
    "25741 agaataataa tgaggctttg gctttgctgg aaatgccgtt ccaaaaaccc attactttat"
    "25801 gatgccaact attttctttg ctggcatact aattgttacg actattgtat accttacaat"
    "25861 agtgtaactt cttcaattgt cattacttca ggtgatggca caacaagtcc tatttctgaa"
    "25921 catgactacc agattggtgg ttatactgaa aaatgggaat ctggagtaaa agactgtgtt"
    "25981 gtattacaca gttacttcac ttcagactat taccagctgt actcaactca attgagtaca"
    "26041 gacactggtg ttgaacatgt taccttcttc atctacaata aaattgttga tgagcctgaa"
    "26101 gaacatgtcc aaattcacac aatcgacggt tcatccggag ttgttaatcc agtaatggaa"
    "26161 ccaatttatg atgaaccgac gacgactact agcgtgcctt tgtaagcaca agctgatgag"
    "26221 tacgaactta tgtactcatt cgtttcggaa gagacaggta cgttaatagt taatagcgta"
    "26281 cttctttttc ttgctttcgt ggtattcttg ctagttacac tagccatcct tactgcgctt"
    "26341 cgattgtgtg cgtactgctg caatattgtt aacgtgagtc ttgtaaaacc ttctttttac"
    "26401 gtttactctc gtgttaaaaa tctgaattct tctagagttc ctgatcttct ggtctaaacg"
    "26461 aactaaatat tatattagtt tttctgtttg gaactttaat tttagccatg gcagattcca"
    "26521 acggtactat taccgttgaa gagcttaaaa agctccttga acaatggaac ctagtaatag"
    "26581 gtttcctatt ccttacatgg atttgtcttc tacaatttgc ctatgccaac aggaataggt"
    "26641 ttttgtatat aattaagtta attttcctct ggctgttatg gccagtaact ttagcttgtt"
    "26701 ttgtgcttgc tgctgtttac agaataaatt ggatcaccgg tggaattgct atcgcaatgg"
    "26761 cttgtcttgt aggcttgatg tggctcagct acttcattgc ttctttcaga ctgtttgcgc"
    "26821 gtacgcgttc catgtggtca ttcaatccag aaactaacat tcttctcaac gtgccactcc"
    "26881 atggcactat tctgaccaga ccgcttctag aaagtgaact cgtaatcgga gctgtgatcc"
    "26941 ttcgtggaca tcttcgtatt gctggacacc atctaggacg ctgtgacatc aaggacctgc"
    "27001 ctaaagaaat cactgttgct acatcacgaa cgctttctta ttacaaattg ggagcttcgc"
    "27061 agcgtgtagc aggtgactca ggttttgctg catacagtcg ctacaggatt ggcaactata"
    "27121 aattaaacac agaccattcc agtagcagtg acaatattgc tttgcttgta cagtaagtga"
    "27181 caacagatgt ttcatctcgt tgactttcag gttactatag cagagatatt actaattatt"
    "27241 atgaggactt ttaaagtttc catttggaat cttgattaca tcataaacct cataattaaa"
    "27301 aatttatcta agtcactaac tgagaataaa tattctcaat tagatgaaga gcaaccaatg"
    "27361 gagattgatt aaacgaacat gaaaattatt cttttcttgg cactgataac actcgctact"
    "27421 tgtgagcttt atcactacca agagtgtgtt agaggtacaa cagtactttt aaaagaacct"
    "27481 tgctcttctg gaacatacga gggcaattca ccatttcatc ctctagctga taacaaattt"
    "27541 gcactgactt gctttagcac tcaatttgct tttgcttgtc ctgacggcgt aaaacacgtc"
    "27601 tatcagttac gtgccagatc agtttcacct aaactgttca tcagacaaga ggaagttcaa"
    "27661 gaactttact ctccaatttt tcttattgtt gcggcaatag tgtttataac actttgcttc"
    "27721 acactcaaaa gaaagacaga atgattgaac tttcattaat tgacttctat ttgtgctttt"
    "27781 tagcctttct gctattcctt gttttaatta tgcttattat cttttggttc tcacttgaac"
    "27841 tgcaagatca taatgaaact tgtcacgcct aaacgaacat gaaatttctt gttttcttag"
    "27901 gaatcatcac aactgtagct gcatttcacc aagaatgtag tttacagtca tgtactcaac"
    "27961 atcaaccata tgtagttgat gacccgtgtc ctattcactt ctattctaaa tggtatatta"
    "28021 gagtaggagc tagaaaatca gcacctttaa ttgaattgtg cgtggatgag gctggttcta"
    "28081 aatcacccat tcagtacatc gatatcggta attatacagt ttcctgttta ccttttacaa"
    "28141 ttaattgcca ggaacctaaa ttgggtagtc ttgtagtgcg ttgttcgttc tatgaagact"
    "28201 ttttagagta tcatgacgtt cgtgttgttt tagatttcat ctaaacgaac aaactaaaat"
    "28261 gtctgataat ggaccccaaa atcagcgaaa tgcaccccgc attacgtttg gtggaccctc"
    "28321 agattcaact ggcagtaacc agaatggaga acgcagtggg gcgcgatcaa aacaacgtcg"
    "28381 gccccaaggt ttacccaata atactgcgtc ttggttcacc gctctcactc aacatggcaa"
    "28441 ggaagacctt aaattccctc gaggacaagg cgttccaatt aacaccaata gcagtccaga"
    "28501 tgaccaaatt ggctactacc gaagagctac cagacgaatt cgtggtggtg acggtaaaat"
    "28561 gaaagatctc agtccaagat ggtatttcta ctacctagga actgggccag aagctggact"
    "28621 tccctatggt gctaacaaag acggcatcat atgggttgca actgagggag ccttgaatac"
    "28681 accaaaagat cacattggca cccgcaatcc tgctaacaat gctgcaatcg tgctacaact"
    "28741 tcctcaagga acaacattgc caaaaggctt ctacgcagaa gggagcagag gcggcagtca"
    "28801 agcctcttct cgttcctcat cacgtagtcg caacagttca agaaattcaa ctccaggcag"
    "28861 cagtagggga acttctcctg ctagaatggc tggcaatggc ggtgatgctg ctcttgcttt"
    "28921 gctgctgctt gacagattga accagcttga gagcaaaatg tctggtaaag gccaacaaca"
    "28981 acaaggccaa actgtcacta agaaatctgc tgctgaggct tctaagaagc ctcggcaaaa"
    "29041 acgtactgcc actaaagcat acaatgtaac acaagctttc ggcagacgtg gtccagaaca"
    "29101 aacccaagga aattttgggg accaggaact aatcagacaa ggaactgatt acaaacattg"
    "29161 gccgcaaatt gcacaatttg cccccagcgc ttcagcgttc ttcggaatgt cgcgcattgg"
    "29221 catggaagtc acaccttcgg gaacgtggtt gacctacaca ggtgccatca aattggatga"
    "29281 caaagatcca aatttcaaag atcaagtcat tttgctgaat aagcatattg acgcatacaa"
    "29341 aacattccca ccaacagagc ctaaaaagga caaaaagaag aaggctgatg aaactcaagc"
    "29401 cttaccgcag agacagaaga aacagcaaac tgtgactctt cttcctgctg cagatttgga"
    "29461 tgatttctcc aaacaattgc aacaatccat gagcagtgct gactcaactc aggcctaaac"
    "29521 tcatgcagac cacacaaggc agatgggcta tataaacgtt ttcgcttttc cgtttacgat"
    "29581 atatagtcta ctcttgtgca gaatgaattc tcgtaactac atagcacaag tagatgtagt"
    "29641 taactttaat ctcacatagc aatctttaat cagtgtgtaa cattagggag gacttgaaag"
    "29701 agccaccaca ttttcaccga ggccacgcgg agtacgatcg agtgtacagt gaacaatgct"
    "29761 agggagagct gcctatatgg aagagcccta atgtgtaaaa ttaattttag t";
*/
    

void setColor()
{
  analogWrite(rpin, rgb[0]);
  analogWrite(gpin, rgb[1]);
  analogWrite(bpin, rgb[2]);
}

void setup()
{                
  // initialize the digital pin as an output.
  for (int i = 1; i < maxled; i++)
    pinMode(i, OUTPUT); 
  setColor();    
}

void nextColor()
{
  rgb[c] = rgb[c]+3;
  if (rgb[c]>255) {
    rgb[c] = 0;
    c++;
    if (c == 3) c = 0;
  }
  int d = c+1;
  if (d == 3) d=0;
  rgb[d] = rgb[d]-3;
  if (rgb[d] < 0)
    rgb[d] = 255;
  setColor();
}

void potColor(int potval)
{
  rgb[0] = potval;
  rgb[1] = 255 - potval;
  rgb[2] = 128;
  setColor();
}

void nextled()
{
  digitalWrite(onled, LOW);
  // delay(50);
  onled += inc;
  if (onled == maxled) {
    onled = maxled -2;
    inc = -1;
  }
  if (onled == minled) {
    onled = minled + 2;
    inc = 1;
  }
  digitalWrite(onled, HIGH);
}
//I equals zawardo
int nucleoidIndex = 0;
bool isValidNucleoid(char n) {
   if (n == 'a' || n == 't' || n == 'c' || n == 'g' ) return true;
   return false;
}

  char getNextNucleoid() {
    char n = genomeSeq[nucleoidIndex];
    nucleoidIndex++;

    while (!isValidNucleoid(n)){
      n = genomeSeq[nucleoidIndex];
      nucleoidIndex++;
      if (n == 0) {
        nucleoidIndex = 0;
        return getNextNucleoid();
      }
    }
    return n;
}
int nucleoidPin(char n) {
  int pin = minled;
  if(n == 'a') return pin;
  pin++;
  if(n == 't') return pin;
  pin++;
  if(n == 'g') return pin;
  pin++;
  if(n == 'c') return pin;
  Serial.println("Bad Amino Acid " + n);
}
void NucleoidLed(int pin){
digitalWrite(onled, LOW);
delay(wtime);
onled = pin;
digitalWrite(onled, HIGH);
}
void loop() {
  char n = getNextNucleoid();
  int pin = nucleoidPin(n);
  NucleoidLed(pin);
  //nextled();
  //nextColor();
  int pval = analogRead(potpin);
  wtime = map(pval, 0, 1023, 20, 400);
  //potColor(map(pval, 0, 1023, 0, 255));
  delay(wtime);
}
