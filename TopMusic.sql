-- MySQL dump 10.13  Distrib 5.7.24, for Linux (i686)
--
-- Host: localhost    Database: TopMusic
-- ------------------------------------------------------
-- Server version	5.7.24-0ubuntu0.18.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Apartenenta_Gen`
--

DROP TABLE IF EXISTS `Apartenenta_Gen`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Apartenenta_Gen` (
  `ID_Gen` int(11) NOT NULL,
  `Id_Melodie` int(11) NOT NULL,
  KEY `fk_ID_Gen` (`ID_Gen`),
  KEY `fk_Id_Melodie` (`Id_Melodie`),
  CONSTRAINT `Apartenenta_Gen_ibfk_1` FOREIGN KEY (`ID_Gen`) REFERENCES `Genuri_Muzicale` (`ID_Gen`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `Apartenenta_Gen_ibfk_2` FOREIGN KEY (`Id_Melodie`) REFERENCES `Melodii` (`Id_Melodie`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Apartenenta_Gen`
--

LOCK TABLES `Apartenenta_Gen` WRITE;
/*!40000 ALTER TABLE `Apartenenta_Gen` DISABLE KEYS */;
INSERT INTO `Apartenenta_Gen` VALUES (12,2271),(11,2271),(10,2271),(1,2272),(5,2272),(6,2272),(1,2273),(9,2274),(15,2275),(1,2276),(15,2276),(1,2277),(15,2277),(7,2278);
/*!40000 ALTER TABLE `Apartenenta_Gen` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Comentarii`
--

DROP TABLE IF EXISTS `Comentarii`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Comentarii` (
  `Id_Melodie` int(11) NOT NULL,
  `Id_User` int(11) NOT NULL,
  `Comment` varchar(128) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Comentarii`
--

LOCK TABLES `Comentarii` WRITE;
/*!40000 ALTER TABLE `Comentarii` DISABLE KEYS */;
INSERT INTO `Comentarii` VALUES (90,0,''),(90,0,''),(90,0,''),(90,0,''),(90,2,'Foarte bine!\n'),(90,2,'Foarte tare'),(2,90,'Nostalgie ;)'),(2,90,'Mai multe decat nostalgie =)'),(2,90,'Imi aduce aminte de =)'),(2275,90,'Nostalgie =)'),(2275,90,'Si mai multa nostalgie =)'),(4,103,''),(2278,103,'Unirea inseamna putere. =)');
/*!40000 ALTER TABLE `Comentarii` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Genuri_Muzicale`
--

DROP TABLE IF EXISTS `Genuri_Muzicale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Genuri_Muzicale` (
  `ID_Gen` int(11) NOT NULL AUTO_INCREMENT,
  `Nume_Gen` varchar(32) NOT NULL,
  PRIMARY KEY (`ID_Gen`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Genuri_Muzicale`
--

LOCK TABLES `Genuri_Muzicale` WRITE;
/*!40000 ALTER TABLE `Genuri_Muzicale` DISABLE KEYS */;
INSERT INTO `Genuri_Muzicale` VALUES (1,'rock'),(2,'pop'),(3,'opera'),(4,'balada'),(5,'hard rock'),(6,'heavy metal'),(7,'imn'),(8,'popular'),(9,'simfonie'),(10,'electronica'),(11,'house'),(12,'dance'),(13,'disco'),(14,'jazz'),(15,'retro');
/*!40000 ALTER TABLE `Genuri_Muzicale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Melodii`
--

DROP TABLE IF EXISTS `Melodii`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Melodii` (
  `Id_Melodie` int(11) NOT NULL AUTO_INCREMENT,
  `Nume` varchar(64) NOT NULL,
  `Descriere` varchar(256) DEFAULT NULL,
  `Link` varchar(128) DEFAULT NULL,
  `Raiting` decimal(4,2) DEFAULT NULL,
  PRIMARY KEY (`Id_Melodie`)
) ENGINE=InnoDB AUTO_INCREMENT=2279 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Melodii`
--

LOCK TABLES `Melodii` WRITE;
/*!40000 ALTER TABLE `Melodii` DISABLE KEYS */;
INSERT INTO `Melodii` VALUES (2271,'Wake Me Up','Artist: Avicii (2013)','https://www.youtube.com/watch?v=IcrbM1l_BoI',9.50),(2272,'Mutter','Rammstein','https://www.youtube.com/watch?v=gNdnVVHfseA',9.00),(2273,'Ohne Dich','Artist: Rammstein (2004)','https://www.youtube.com/watch?v=LIPc1cfS-oQ',9.00),(2274,'The Four Seasons','Compozitor: Antonio Vivaldi(1721)','https://www.youtube.com/watch?v=GRxofEmo3HA&t=375s',9.75),(2275,'Brother Louie','Artist: Modern Talking (1986)','https://www.youtube.com/watch?v=Lp2qcCrdBLA',9.50),(2276,'I want to break free','Artist: Queen (1984)','https://www.youtube.com/watch?v=f4Mc-NYPHaQ',10.00),(2277,'The Star with the name Sun','Artist: Kino','https://www.youtube.com/watch?v=5M2FNxhtrq8',9.67),(2278,'Hora Unirii','Autor: Vasile Alecsandri','https://www.youtube.com/watch?v=jEUfTba6ZE8',9.50);
/*!40000 ALTER TABLE `Melodii` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Note`
--

DROP TABLE IF EXISTS `Note`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Note` (
  `Id_Melodie` int(11) DEFAULT NULL,
  `Nota` int(11) DEFAULT NULL,
  `Id_User` int(11) DEFAULT NULL,
  KEY `Id_Melodie` (`Id_Melodie`),
  KEY `Id_User` (`Id_User`),
  CONSTRAINT `Note_ibfk_1` FOREIGN KEY (`Id_Melodie`) REFERENCES `Melodii` (`Id_Melodie`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `Note_ibfk_2` FOREIGN KEY (`Id_User`) REFERENCES `Users` (`Id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Note`
--

LOCK TABLES `Note` WRITE;
/*!40000 ALTER TABLE `Note` DISABLE KEYS */;
INSERT INTO `Note` VALUES (2271,10,90),(2272,9,90),(2274,10,90),(2274,9,90),(2274,10,90),(2273,8,90),(2271,9,90),(2274,10,90),(2276,10,90),(2275,9,90),(2277,9,90),(2276,10,90),(2278,9,90),(2273,10,90),(2278,10,90),(2277,10,90),(2275,10,90),(2277,10,90);
/*!40000 ALTER TABLE `Note` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Users`
--

DROP TABLE IF EXISTS `Users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Users` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(64) NOT NULL,
  `hash_of_password` varchar(72) NOT NULL,
  `isAdmin` int(11) DEFAULT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=104 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Users`
--

LOCK TABLES `Users` WRITE;
/*!40000 ALTER TABLE `Users` DISABLE KEYS */;
INSERT INTO `Users` VALUES (90,'Sorin\n','225a84aab4f089186fda9bfea0d60271f25a6a536b9ee0581e3d50236e1956de',0),(91,'Tudor\n','cc19ad25eef37f441971eda5de429ad5bdbb5b6bcb45d20de22c48778fbc29a7',0),(92,'Dorina\n','b805470e1885d4371b442179a22741575d51002ddc0ad5ca52fda5038e0ccc00',0),(93,'Alex\n','fb2b7fce0940161406a6aa3e4d8b4aa6104014774ffa665743f8d9704f0eb0ec',0),(94,'Robin Hood\n','6b86b273ff34fce19d6b804eff5a3f5747ada4eaa22f1d49c01e52ddb7875b4b',0),(95,'Sorin\n','e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855',0),(96,'dfljs\n','5feceb66ffc86f38d952786c6d696c79c2dbc239dd4e91b46729d73a27fb57e9',0),(97,'Sorin\n','fa809045d9192f770781794da417b564c3ecb66f356b58c060a9cbba7d5224c8',0),(98,'Tudor\n','fa809045d9192f770781794da417b564c3ecb66f356b58c060a9cbba7d5224c8',0),(99,'Astrind\n','225a84aab4f089186fda9bfea0d60271f25a6a536b9ee0581e3d50236e1956de',0),(100,'Sorin\n','cc19ad25eef37f441971eda5de429ad5bdbb5b6bcb45d20de22c48778fbc29a7',0),(101,'Sorin\n','b805470e1885d4371b442179a22741575d51002ddc0ad5ca52fda5038e0ccc00',0),(102,'Clayton\n','b805470e1885d4371b442179a22741575d51002ddc0ad5ca52fda5038e0ccc00',0),(103,'Sorin\n','f9194e73f9e9459e3450ea10a179cdf77aafa695beecd3b9344a98d111622243',1);
/*!40000 ALTER TABLE `Users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-01-18 14:46:57
