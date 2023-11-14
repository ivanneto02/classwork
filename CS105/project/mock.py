import pandas as pd
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.feature_extraction.text import CountVectorizer

def main():

    pd.options.display.max_colwidth = 250

    corpus = ["The Battle of Vrbanja Bridge occurred on 27 May 1995 between United Nations peacekeepers from the French Army and elements of the Bosnian Serbaligned Army of Republika Srpska (VRS). It began after the VRS seized French-manned observation posts of the United Nations Protection Force at both ends of the Vrbanja Bridge in Sarajevo, Bosnia and Herzegovina, during the Bosnian War, taking twelve French peacekeepers hostage. Two of them remained held at the bridge as human shields. A platoon of 30 French peacekeepers, led by then-Captain François Lecointre, recaptured the bridge with the support of 70 French infantrymen and direct fire from armoured vehicles. Two French soldiers were killed and seventeen were wounded during the battle. VRS casualties were four killed, several wounded and four captured. VRS forces were subsequently less likely to engage French UN peacekeepers deployed in the city. In 2017, Lecointre was appointed Chief of the Defence Staff of France with the rank of army general.", 
            "The Roman emperors were the rulers of the Roman Empire from the granting of the title Augustus to Octavian (pictured) in 27 BC. The English word emperor derives from imperator, an ancient honorific that served as one of the several titles of the emperor. Early emperors ruled behind a republican facade and avoided monarchical titles, but this changed over the following centuries, after which the position became more akin to an absolute monarchy. After the Crisis of the Third Century, the empire was split into a Greek East and Latin West, each with its own emperor. The Western Empire fell to foreign invaders in 476, marking the traditional start of the Middle Ages in Europe. The Eastern Empire, or Byzantine Empire, continued for another thousand years until the Fall of Constantinople in 1453, marking the end of the medieval period, although its power and extent had long been in decline. Several foreign rulers have also claimed the title of Roman emperor, regarding themselves as the true successors to Roman civilization.", 
            "The style of government instituted by Augustus is called the Principate and continued until the late third or early fourth century.[4] The modern word derives from the title imperator, which was granted by an army to a successful general; during the initial phase of the empire, the title was generally used only by the princeps.[5] For example, Augustus's official name was Imperator Caesar Divi Filius Augustus.[6] The territory under command of the emperor had developed under the period of the Roman Republic as it invaded and occupied much of Europe and portions of North Africa and the Middle East. Under the republic, the Senate and People of Rome authorized provincial governors, who answered only to them, to rule regions of the empire.[7] The chief magistrates of the republic were two consuls elected each year; consuls continued to be elected in the imperial period, but their authority was subservient to that of the emperor, who also controlled and determined their election.[8] Oftentimes, the emperors themselves, or close family, were selected as consul", 
            "After the Crisis of the Third Century, Diocletian increased the authority of the emperor and adopted the title (our lord). The rise of powerful barbarian tribes along the borders of the empire, the challenge they posed to the defense of far-flung borders as well as an unstable imperial succession led Diocletian to divide the administration of the Empire geographically with a co-augustus in 286. In 330, Constantine the Great, the emperor who accepted Christianity, established a second capital in Byzantium, which he renamed Constantinople. Historians consider the Dominate period of the empire to have begun with either Diocletian or Constantine, depending on the author.[10] For most of the period from 286 to 480, there was more than one recognized senior emperor, with the division usually based on geographic regions. This division was consistently in place after the death of Theodosius I in 395, which historians have dated as the division between the Western Roman Empire and the Eastern Roman Empire. However, formally the Empire remained a single polity, with separate co-emperors in the separate courts", 
            "The fall of the Western Roman Empire is dated either from the de facto date of 476, when Romulus Augustulus was deposed by the Germanic Herulians led by Odoacer, or the de jure date of 480, on the death of Julius Nepos, when Eastern emperor Zeno ended recognition of a separate Western court.[12][13] Historians typically refer to the empire in the centuries that followed as the, oriented towards Hellenic culture and governed by the Byzantine emperors.[a] Given that is a later historiographical designation and the inhabitants and emperors of the empire continually maintained Roman identity, this designation is not used universally and continues to be a subject of specialist debate.[b] Under Justinian I, in the sixth century, a large portion of the western empire was retaken, including Italy, Africa, and part of Spain.[17] Over the course of the centuries thereafter, most of the imperial territories were lost, which eventually restricted the empire to Anatolia and the Balkans.[c] The line of emperors continued until the death of Constantine XI Palaiologos at the fall of Constantinople in 1453, when the remaining territories were conquered by the Ottoman Turks led by Sultan Mehmed II.[23][g] In the aftermath of the conquest, Mehmed II proclaimed himself kayser-i Rûm,[h] thus claiming to be the new emperor,[30] a claim maintained by succeeding sultans.[31] Competing claims of succession to the Roman Empire have also been forwarded by various other states and empires, and by numerous later pretenders."
            ]
    
    df = pd.DataFrame(data=corpus, columns=["strings"])

    print(df.head(15))

    cv = CountVectorizer(max_features=10)
    word_count_vector = cv.fit_transform(df["strings"])

    tfidf = TfidfTransformer()
    tfidf.fit(word_count_vector)
    tfidf_corpus = tfidf.transform(word_count_vector)

    df["tfidf"] = [ x.toarray()[0] for x in tfidf_corpus ]

    for row in df["tfidf"]:
        print(len(row))

    print(df["tfidf"].head(10))

    df.to_csv("./test.csv", index=False)

    # print(df.sort_values(by=["tfidf"], ascending=False))

    # df_idf = pd.DataFrame(tfidf_corpus[0].T.todense(), columns=["idf_weights"]) 
    # df_idf.sort_values(by=["idf_weights"], ascending=False, inplace=True)

    # print(df_idf.head(20))

if __name__ == "__main__":
    main()