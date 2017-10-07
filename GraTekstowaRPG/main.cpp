// GraTekstowaRPG.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <conio.h>
#include <time.h>
#include <string>
#include <string.h>

using namespace std;

class Hero
{

public:
	int AttackPoints;
	int Defense;
	int heroMana;
	int heroAura;
	int Strength;
	int hp;
	int maxhp;
	int pieniadze;
	int poziom;
private:

protected:

public:
	Hero()
	{

		Defense = 5;
		heroMana = 10;
		heroAura = 10;
		Strength = 7;
		poziom = 1;
		hp = 70;
		maxhp = 70;
		AttackPoints = 1.5*Strength;
		pieniadze = 0;
	}
	friend class Item;
	friend class WeaponItem;
	friend class MagicItem;
	friend class ScrollItem;
	void wyswietl_staty()
	{
		cout << "Twoje statystyki: " << endl;
		cout << "Punkty zycia: " << this->hp << endl;
		cout << "Sila: " << this->Strength << endl;
		cout << "Obrona: " << this->Defense << endl;
		cout << "Punkty ataku: " << this->AttackPoints << endl;
		cout << "Punkty many: " << this->heroMana << endl;
		cout << "Sila aury: " << this->heroAura << endl;
		cout << endl;
	}
	void levelup()
	{
		if (this->poziom == 2)
		{
			this->Defense += 3;
			this->Strength += 3;
			this->AttackPoints = 1.5*Strength;
			this->hp = 100;
			this->maxhp += 30;
			this->heroAura += 5;
			this->heroMana += 5;
		}
		if (this->poziom == 3)
		{
			this->Defense += 5;
			this->Strength += 3;
			this->AttackPoints = 1.5*Strength;
			this->hp = 200;
			this->maxhp = 200;
			this->heroAura += 5;
			this->heroMana += 5;
		}
	}
	void checkhp()
	{
		if (this->hp > this->maxhp)
		{
			this->hp = this->maxhp;
		}
	}
	void hpreduce(int attackvalue)
	{
		if (attackvalue > 0)
		{
			this->hp -= (attackvalue - Defense);
		}
		if (attackvalue == 0)
		{
			this->hp == this->hp;
		}
		if (this->hp <= 0)
		{
			this->hp = 0;
			cout << "Nie zyjesz" << endl;
		}
	}
	void gethealed(int healvalue)
	{
		this->hp += healvalue;
	}
};

class Potwor
{
private:
	int attack;
	int defense;
	int accuracy;
public:
	int random;
	int hp;
	int maxhp;
	string name;
	virtual int atak() = 0;
	//virtual int atak2() = 0;
	virtual void hpreduce(int attackvalue) = 0;
	friend class Goblin;
	friend class Troll;
};

class Goblin : public Potwor
{
public:
	Goblin()
	{
		hp = 15;
		maxhp = 15;
		attack = 10;
		defense = 5;
		accuracy = 50;
		name = "Goblin";
	}
	Goblin(int a)
	{
		if (a == 100)
		{
			hp = 250;
			maxhp = 250;
			attack = 35;
			defense = 15;
			accuracy = 75;
			name = "Krol Goblinow";
		}
	}
	Goblin::~Goblin()
	{
		cout << "Goblin zabity" << endl;
		delete this;
	}
	void Kill()
	{
		cout << "Goblin zabity" << endl;
		delete this;
	}
	int atak()
	{
		random = rand() % 100;
		if (random >= 50)
		{
			cout << "Przeciwnik trafia szybkim atakiem! " << endl;
			return attack;
		}
		else
		{
			cout << "Przeciwnik nie trafil szybkim atakiem! " << endl;
			return 0;
		}
	}

	int atak2()
	{
		random = rand() % 100;
		if (random >= 70)
		{

			cout << "Przeciwnik trafia silniejszm atakiem! " << endl;
			return attack*1.5;
		}
		else
		{
			cout << "Przeciwnik nie trafil silniejszym atakiem! " << endl;
			return 0;
		}
	}
	void hpreduce(int attackvalue)
	{
		if (attackvalue > 0)
		{
			this->hp -= (attackvalue - defense);
		}
		if (attackvalue == 0)
		{
			this->hp == this->hp;
		}
		if (this->hp <= 0)
		{
			this->hp = 0;
		}
	}


};



class Troll : public Potwor
{
public:
	Troll()
	{
		name = "Troll Jaskiniowy ";
		attack = 50;
		defense = 7;
		accuracy = 35;
		hp = 70;
		maxhp = 70;
	}
	int atak()
	{
		random = rand() % 100;
		if (random >= (100 - accuracy))
		{
			cout << "Przeciwnik trafia swoim atakiem! " << endl;
			return attack;
		}
		else
		{
			cout << "Przeciwnik nie trafil swoim atakiem! " << endl;
			return 0;
		}
	}
	void hpreduce(int attackvalue)
	{
		if (attackvalue > 0)
		{
			this->hp -= (attackvalue - defense);
		}
		if (attackvalue == 0)
		{
			this->hp == this->hp;
		}
		if (this->hp <= 0)
		{
			this->hp = 0;
		}
	}
};

class Storage
{
private:
	int size2;
	bool full;

public:
	string * tab;
	virtual void getSize() = 0;
	virtual void setFull(string *tab) = 0;
	virtual void getFull() = 0;
	friend class BagpackStorage;
};

class BagpackStorage : public Storage
{
private:
	int requiredStrength;
	int * owner;
	int udzwig;
	int udzwig2;
public:

	BagpackStorage()
	{
		requiredStrength = 7;
		size2 = 5;
		udzwig = 0;
		udzwig2 = 15;
		full == false;
		tab = new string[size2];
		for (int a = 0; a < size2; a++)
		{
			tab[a] = "WOLNE MIEJSCE";
		}

	}
	void getSize()
	{
		cout << "Rozmiar plecaka: " << size2 << endl;
	}
	void getFull()
	{
		if (full == false)
		{
			cout << "W plecaku jest jeszcze miejsce " << endl;
		}
		if (full == true)
		{
			cout << "Plecak jest juz pelny " << endl;
		}
	}
	void setFull(string *tab)
	{
		full == true;
		for (int a = 0; a < size2; a++)
		{
			if (tab[a] == "WOLNE MIEJSCE")
			{
				full == false;
				break;
			}
		}
	}
	void showContent(string *tab)
	{
		//sprintf_s(, "Blyskawica");
		//tab[5] == "Ostrze";
		//tab[0] == "Siema";
		cout << endl;
		cout << "Udzwig plecaka: " << udzwig << "/" << udzwig2 << endl;
		cout << "Zawartosc plecaka: " << endl;
		for (int a = 0; a < size2; a++)
		{
			cout << a + 1 << " " << tab[a] << endl;
		}
	}
	void addItem(string item)
	{
		if (full == false)
		{
			for (int a = 0; a < size2; a++)
			{
				if (tab[a] == "WOLNE MIEJSCE")
				{

					tab[a] = item;
					break;
				}
			}
		}
		setFull(tab);
		getFull();
	}
	void addweight(int waga)
	{
		udzwig = udzwig + waga;
	}
	void reduceweight(int waga)
	{
		udzwig -= waga;
	}
	void removeItem(string item)
	{
		for (int a = 0; a < size2; a++)
		{
			if (tab[a] == item)
			{

				tab[a] = "WOLNE MIEJSCE";
				break;
			}
		}
	}

};

class Unique
{
private:
	string creator;
	int specialStats;
public:
	virtual void getCreator() = 0;
	virtual void getSpecialStats() = 0;
	friend class UniqueWeaponItem;
	friend class UniqueArmorItem;
};



class Item
{
private:
	int value;
	bool identified;
public:
	float condition;
	float condition2;
	int weight;
	string name;
	void identify()
	{
		bool identify = true;
	}
	void getCondition()
	{
		cout << "Wytrzymalosc przedmiotu wynosi: " << condition << endl;
	}
	string getName()
	{
		return name;
	}
	void getValue()
	{
		cout << "Wartosc przedmiotu: " << value << endl;
	}
	void getWeight()
	{
		cout << "Ciezar przedmiotu: " << weight << endl;
	}
	friend class UniqueWeaponItem;
	friend class WeaponItem;
	friend class ArmorItem;
	friend class MagicItem;
};

class WeaponItem : public Item
{
private:
	int handedness;
	string type;
public:
	int accuracy;
	int accuracy2;
	bool equipped;
	int random;
	WeaponItem()
	{
		this->name = "Drewniana Palka";
		this->handedness = 1;
		this->value = 5;
		this->weight = 3;
		this->type = "melee";
		this->accuracy = 50;
		this->accuracy2 = 30;
		this->condition = 20;
		this->condition2 = 20;
	}
	WeaponItem(int a)
	{
		if (a == 1)
		{
			this->name = "Zardzewialy miecz ";
			this->handedness = 1;
			this->value = 8;
			this->weight = 5;
			this->type = "melee";
			this->accuracy = 60;
			this->accuracy2 = 35;
			this->condition = 20;
			this->condition2 = 20;
		}
		if (a == 2)
		{
			this->name = "Kolczasty Obuch Trolla Jaskiniowego ";
			this->handedness = 1;
			this->value = 20;
			this->weight = 10;
			this->type = "melee";
			this->accuracy = 70;
			this->accuracy2 = 40;
			this->condition = 20;
			this->condition2 = 20;
		}
	}
	void showStats()
	{
		cout << "Nazwa przedmiotu: " << this->name << endl;
		if (handedness == 1)
		{
			cout << "Rodzaj broni: Jednoreczna " << this->type << endl;
		}
		else
		{
			cout << "Rodzaj broni: Dwureczna " << this->type << endl;
		}
		cout << "Wartosc: " << this->value << " g" << endl;
		cout << "Waga: " << this->weight << endl;
		cout << "Celnosc: " << this->accuracy << "%" << endl;
		cout << "Stan: " << this->condition << "/" << this->condition2 << endl;
	}
	void getType()
	{
		cout << "Typ broni: " << type << endl;
	}
	int attack(int heroAttackPoints)
	{
		random = rand() % 100;
		if (random >= accuracy)
		{
			cout << "Udalo sie trafic przeciwnika! " << endl;
			return heroAttackPoints;
		}
		else
		{
			cout << "Nie trafiles! " << endl;
			return 0;
		}
	}
	int attack2(int heroAttackPoints)
	{
		random = rand() % 100;
		if (random >= (100 - accuracy2))
		{
			cout << "Udalo sie trafic przeciwnika! " << endl;
			return heroAttackPoints*1.5;
		}
		else
		{
			cout << "Nie trafiles! " << endl;
			return 0;
		}
	}
	friend class UniqueWeaponItem;
};

class UniqueWeaponItem : public Unique, public WeaponItem
{
public:
	UniqueWeaponItem()
	{
		WeaponItem::handedness = 1;
		specialStats = 8;
		creator = "Ostrze Chaosu";
		name = "Ostrze Chaosu";
	}
	void getCreator()
	{
		cout << "Znalazles artefakt: " << creator << endl;
	}
	string getName()
	{
		return name;
	}
	void getSpecialStats()
	{
		specialStats = 8;
	}
	void specialAttack(int AttackPoints)
	{
		if (handedness == 1)
		{
			cout << "Zadano " << AttackPoints + specialStats << " obrazen " << endl;
		}
		if (handedness == 2)
		{
			cout << "Zadano " << AttackPoints + 1.5*specialStats << "obrazen " << endl;
		}
	}

};

class ArmorItem : public Item
{
private:

	int durability;
	int minimumStrength;
public:
	int defensePoints;
	bool equipped;
	int regenhp;
	ArmorItem()
	{
		this->name = "Swiecaca Zbroja Goblinow";
		this->defensePoints = 5;
		this->value = 15;
		this->weight = 5;
		this->condition = 25;
		this->condition2 = 25;
		this->regenhp = 3;
	}
	int regen()
	{
		if (this->name == "Swiecaca Zbroja Goblinow")
		{
			return regenhp;
		}
		else
		{
			return 0;
		}
	}
	void showStats()
	{
		cout << "Nazwa przedmiotu: " << this->name << endl;
		cout << "Punkty Obrony: " << this->defensePoints << endl;
		cout << "Wartosc: " << this->value << " g" << endl;
		cout << "Waga: " << this->weight << endl;
		cout << "Stan: " << this->condition << "/" << this->condition2 << endl;
		this->special();
	}
	void special()
	{
		if (this->name == "Swiecaca Zbroja Goblinow")
		{
			cout << "Atrybuty specjalne: Zbroja po kazdej turze odnawia 3 punkty hp " << endl;
		}
	}
	void getDefense()
	{
		cout << "Obrona przedmiotu: " << defensePoints << endl;
	}
	void getDurability()
	{
		cout << "Wytrzymalosc przedmiotu: " << durability << endl;
	}
	void getMinimumStrength()
	{
		cout << "Wymagana sila: " << minimumStrength << endl;
	}
	void defense(int attackValue, int heroDefense)
	{
		if (attackValue > heroDefense)
		{
			cout << "Tracisz " << attackValue - heroDefense << " punktow zycia" << endl;
		}
		else
		{
			cout << "Przedmiot zaabsorbowal cale uderzenie " << endl;
		}
	}
};

class MagicItem : public Item
{
private:
	int requiredMana;
	int healvalue;
public:
	MagicItem()
	{
		this->name = "Maly zwoj leczenia";
		this->requiredMana = 5;
		this->healvalue = 20;
		this->value = 3;
		this->weight = 2;
		this->condition = 1;
		this->condition2 = 1;
	}
	MagicItem(int a)
	{
		if (a == 5)
		{
			this->name = "Duzy zwoj leczenia";
			this->requiredMana = 10;
			this->healvalue = 50;
			this->value = 10;
			this->weight = 3;
			this->condition = 1;
			this->condition2 = 1;
		}
	}
	void showStats()
	{
		cout << "Nazwa przedmiotu " << this->name << endl;
		cout << "Wymagana ilosc many: " << this->requiredMana << endl;
		cout << "Wartosc: " << this->value << endl;
		cout << "Waga przedmiotu: " << this->weight << endl;
		cout << "Ilosc uzyc: " << this->condition << endl;
	}
	void getRequiredMana()
	{
		cout << "Wymagana ilosc many: " << requiredMana << endl;
	}
	int heal(int heromana, int herohp, int heromaxhp)
	{
		if (heromana >= requiredMana)
		{
			cout << "Leczenie zakonczone sukcesem " << endl;
			condition--;
			return healvalue;
		}
		else
		{
			cout << "Masz za malo many " << endl;
		}
		if (healvalue > (heromaxhp - herohp))
		{
			cout << "Czesciowe leczenie zakonczone sukcesem " << endl;
			condition--;
			return healvalue - (heromaxhp - herohp);
		}
		else
		{
			cout << "Leczenie zakonczone sukcesem " << endl;
			condition--;
			return healvalue;
		}
	}

	friend class ScrollItem;
	friend class RuneItem;
};

class RuneItem : public MagicItem
{
private:
	int runePower;
	char magicType[20];
	char magicType2[20];
public:
	int losowymagicType;
	RuneItem()
	{
		runePower = 15;
		losowymagicType = rand() % 3;
		if (losowymagicType == 0)
		{
			//string magicType = new char[20];
			//string magicType2 = new char[20];
			sprintf_s(magicType, "Ogien");
			sprintf_s(magicType2, "Ognia");
		}
		if (losowymagicType == 1)
		{
			//string magicType = new char[20];
			//string magicType2 = new char[20];
			sprintf_s(magicType, "Blyskawica");
			sprintf_s(magicType2, "Blyskawicy");
		}
		if (losowymagicType == 2)
		{
			//string magicType = new char[20];
			//string magicType2 = new char[20];
			sprintf_s(magicType, "Magia");
			sprintf_s(magicType2, "Magii");
		}
	}
	void magicAttack(int heroMana)
	{
		if (heroMana >= requiredMana)
		{
			cout << "Udalo sie wykonac magiczny atak! " << endl;
			cout << "Zadano " << runePower << " obrazen od " << magicType2 << endl;
		}
		else
		{
			cout << "Nie udalo sie wykonac magicznego ataku " << endl;
			cout << "Masz za malo many " << endl;
		}
	}
};

class UniqueArmorItem : public ArmorItem, public Unique
{
private:
	int magicDurability;
public:
	UniqueArmorItem()
	{
		magicDurability = 10;
		specialStats = 20;
		creator = "Swieta Zbroja Slonca";
		name = "Swieta Zbroja Slonca";
	}
	void getCreator()
	{
		cout << "Znalazles artefakt: " << creator << endl;
	}
	void getSpecialStats()
	{
		cout << "Artefakt posiada " << specialStats << " Odpornosci na obrazenia " << endl;
	}
	void SpecialDefense(int attackValue, int heroDefense)
	{
		cout << "Zaatakowano Cie za " << attackValue << " obrazen" << endl;
		if (attackValue - heroDefense - specialStats > 0)
		{
			cout << "Otrzymujesz " << attackValue - heroDefense - specialStats << " obrazen" << endl;
			magicDurability--;
		}
		else
		{
			cout << "Udalo sie zaabsorbowac cale uderzenie " << endl;
			magicDurability - 2;
		}
	}
	void MagicCounterAttack(int heroAura)
	{
		cout << "Zadano " << heroAura + 0.5*specialStats << " obrazen" << endl;
	}
};

class ScrollItem : public MagicItem
{
public:
	int travelRange;
	int travelLength;
public:
	ScrollItem()
	{
		travelRange = 10;
		travelLength = 7;
		MagicItem::requiredMana = 20;
	}
	bool openPortal(int travelLength, int  heroMana)
	{

		if (travelRange >= travelLength && heroMana >= requiredMana)
		{
			cout << "Udalo sie otworzyc portal" << endl;
			return true;
		}
		else
		{
			cout << "Nie udalo sie otworzyc portalu " << endl;
			if (travelRange<travelLength)
			{
				cout << "Jestes zbyt daleko " << endl;
			}
			if (heroMana<requiredMana)
			{
				cout << "Masz za malo many " << endl;
			}
			return false;
		}

	}


};

void zasady_powitanie()
{
	cout << "Witaj w grze Pojedynki RPG! " << endl;
	cout << "Twoim zadaniem jest pokonanie krola goblinow " << endl;
	cout << "Czekaja Cie 4 walki " << endl;
	cout << "Na start otrzymujesz drewniana palke i plecak na przechowanie do 5 przedmiotow" << endl;
	cout << "Powodzenia!" << endl;

}
void przejscie_gry()
{
	cout << "Gratulacje! Udalo Ci sie ukonczyc gre! " << endl;
}


int main()
{
	srand(time(NULL));
	char instrukcja;
	int random_attack;
	char zalozyc;
	//string * tablica = new string[10];
	zasady_powitanie();
	Hero * H = new Hero;
	H->wyswietl_staty();
	WeaponItem * palka = new WeaponItem;
	palka->showStats();
	palka->equipped = true;
	MagicItem * maly_zwoj = new MagicItem;
	cout << endl;
	cout << "Otrzymujesz " << maly_zwoj->name << endl;
	maly_zwoj->showStats();
	BagpackStorage *B = new BagpackStorage;
	B->addItem(maly_zwoj->name);
	B->addweight(maly_zwoj->weight);
	B->showContent(B->tab);
	cout << endl;
	Goblin * goblin = new Goblin;
	cout << "POZIOM 1 " << endl;
	cout << "Jaskinia goblinow " << endl;
	cout << "Wchodzac do jaskini oprocz szybkiego bicia swojego serca, slyszysz rowniez kroki nieznanej Ci istoty " << endl;
	cout << "Powoli zza rogu zaczynasz dostrzegac sylwetke postaci " << endl;
	cout << "Twoim oczom ukazuje sie " << goblin->name << endl;
	cout << "Rozpoczynanie walki " << endl;
	instrukcja = 'b';
	while (instrukcja != 'q')
	{
		cout << endl;
		cout << "Stan rozgrywki 1.1 (POZIOM/WALKA) " << endl;
		cout << endl;
		cout << "Twoje zycie: " << H->hp << "/" << H->maxhp << endl;
		cout << endl;
		cout << "Zycie przeciwnika " << goblin->hp << "/" << goblin->maxhp << endl;
		cout << endl;
		if (goblin->hp == 0)
		{
			instrukcja == 'q';
			break;
		}
		cout << "Wcisnij a, aby zaatakowac przeciwnika zwyklym atakiem (" << palka->accuracy << " % szans)" << endl;
		cout << "Wcisnij z, aby zaatakowac przeciwnika silniejszym atakiem (" << palka->accuracy2 << " % szans)" << endl;
		cout << "Wcisnij e, aby uzyc przedmiotu " << endl;
		cout << "Wcisnij p, aby wyswietlic zawartosc plecaka " << endl;

		cin >> instrukcja;

		switch (instrukcja)
		{
		case 'a':
		{
			cout << "zwykly atak" << endl;
			goblin->hpreduce(palka->attack(H->AttackPoints));
			cout << endl;
			if (goblin->hp > 0)
			{
				cout << "Tura " << goblin->name << "a" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(goblin->atak());
				}
				if (random_attack == 1)
				{
					H->hpreduce(goblin->atak2());
					break;
				}
			}
			break;
		}
		case 'z':
		{
			cout << "silniejszy atak" << endl;
			goblin->hpreduce(palka->attack2(H->AttackPoints));
			cout << endl;
			if (goblin->hp > 0)
			{
				cout << "Tura " << goblin->name << "a" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(goblin->atak());
				}
				if (random_attack == 1)
				{
					H->hpreduce(goblin->atak2());
					break;
				}
			}
			break;
		}
		case 'p':
		{
			B->showContent(B->tab);
			break;
		}
		case 'e':
		{
			int przedmiot;
			B->showContent(B->tab);

			do
			{
				cout << "Ktorego przedmiotu chcesz uzyc? " << endl;
				cin >> przedmiot;
			} while (B->tab[przedmiot - 1] == "WOLNE MIEJSCE");

			if (B->tab[przedmiot - 1] == "Maly zwoj leczenia")
			{
				H->gethealed(maly_zwoj->heal(H->heroMana, H->hp, H->maxhp));
				if (maly_zwoj->condition == 0)
				{
					B->removeItem(maly_zwoj->name);
					B->reduceweight(maly_zwoj->weight);
				}
			}
			if (goblin->hp > 0)
			{
				cout << "Tura " << goblin->name << "a" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(goblin->atak());
				}
				if (random_attack == 1)
				{
					H->hpreduce(goblin->atak2());
					break;
				}
			}
			break;
		}
		}
	}
	cout << "Przeciwnik pokonany. Walka 1 zakonczona sukcesem " << endl;
	cout << endl;
	cout << "Otrzymujesz " << 10 << "zlotych monet " << endl;
	cout << endl;
	H->pieniadze += 10;
	WeaponItem * zardzewialy_miecz = new WeaponItem(1);
	cout << "Znajdujesz " << zardzewialy_miecz->name << endl;
	zardzewialy_miecz->showStats();
	cout << "Czy chcesz go teraz zalozyc? y/n " << endl;
	cin >> zalozyc;
	if (zalozyc == 'y')
	{
		palka->equipped = false;
		B->addItem(palka->name);
		B->addweight(palka->weight);
		zardzewialy_miecz->equipped = true;
		H->Strength += 3;
		H->AttackPoints = 1.5*H->Strength;
		cout << "Twoja bron to teraz " << zardzewialy_miecz->name << endl;
		cout << "Przedmiot " << palka->name << " schowano do plecaka " << endl;
		B->showContent(B->tab);
	}
	else
	{
		B->addItem(zardzewialy_miecz->name);
		B->addweight(zardzewialy_miecz->weight);
		cout << "Przedmiot " << zardzewialy_miecz->name << " schowano do plecaka " << endl;
		B->showContent(B->tab);
	}
	cout << "Odglosy walki i umierajacego Goblina dal sie uslyszec w duzej czesci jaskini " << endl;
	cout << "Slyszysz bieg i krzyk kilku osobnikow w nieznanym Ci jezyku " << endl;
	cout << "Na pole walki wybiegaja 3 gobliny " << endl;
	cout << "Widok martwego kompana tylko pogarsza Twoja sytuacje " << endl;
	cout << "Rozpoczynanie Walki 2" << endl;
	Goblin * goblin1 = new Goblin;
	Goblin * goblin2 = new Goblin;
	Goblin * goblin3 = new Goblin;
	while (instrukcja != 'q')
	{
		if (H->hp == 0)
		{
			instrukcja == 'q';
			cout << "Nie zyjesz. Przegrales " << endl;
			break;
		}
		cout << endl;
		cout << "Stan rozgrywki 1.2 (POZIOM/WALKA) " << endl;
		cout << endl;
		cout << "Twoje zycie: " << H->hp << "/" << H->maxhp << endl;
		cout << endl;
		cout << "Zycie przeciwnika " << goblin1->hp << "/" << goblin1->maxhp << endl;
		cout << endl;
		cout << "Zycie przeciwnika " << goblin2->hp << "/" << goblin2->maxhp << endl;
		cout << endl;
		cout << "Zycie przeciwnika " << goblin3->hp << "/" << goblin3->maxhp << endl;
		cout << endl;
		if (goblin1->hp == 0 && goblin2->hp == 0 && goblin3->hp == 0)
		{
			instrukcja == 'q';
			break;
		}
		if (goblin1->hp == 0 && goblin2->hp == 0 && goblin3->hp == 0)
		{
			instrukcja == 'q';
			break;
		}
		cout << "Wcisnij a, aby zaatakowac przeciwnika zwyklym atakiem (" << zardzewialy_miecz->accuracy << " % szans)" << endl;
		cout << "Wcisnij z, aby zaatakowac przeciwnika silniejszym atakiem (" << zardzewialy_miecz->accuracy2 << " % szans)" << endl;
		cout << "Wcisnij e, aby uzyc przedmiotu " << endl;
		cout << "Wcisnij p, aby wyswietlic zawartosc plecaka " << endl;

		cin >> instrukcja;

		switch (instrukcja)
		{
		case 'a':
		{
			cout << "atak" << endl;
			if (goblin1->hp > 0)
			{
				goblin1->hpreduce(zardzewialy_miecz->attack(H->AttackPoints));
			}
			else if (goblin1->hp == 0 && goblin2->hp>0)
			{
				goblin2->hpreduce(zardzewialy_miecz->attack(H->AttackPoints));
			}
			else if (goblin1->hp == 0 && goblin2->hp == 0 && goblin3->hp>0)
			{
				goblin3->hpreduce(zardzewialy_miecz->attack(H->AttackPoints));
			}
			cout << endl;
			if (goblin1->hp > 0)
			{
				cout << "Tura " << goblin1->name << "a pierwszego" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(goblin1->atak());
				}
				if (random_attack == 1)
				{
					H->hpreduce(goblin1->atak2());

				}
			}
			if (goblin2->hp > 0)
			{
				cout << "Tura " << goblin2->name << "a drugiego" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(goblin2->atak());
				}
				if (random_attack == 1)
				{
					H->hpreduce(goblin2->atak2());

				}
			}
			if (goblin3->hp > 0)
			{
				cout << "Tura " << goblin3->name << "a trzeciego" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(goblin3->atak());
				}
				if (random_attack == 1)
				{
					H->hpreduce(goblin3->atak2());

				}
			}
			break;
		}
		case 'z':
		{
			cout << "atak" << endl;
			if (goblin1->hp > 0)
			{
				goblin1->hpreduce(zardzewialy_miecz->attack2(H->AttackPoints));
			}
			else if (goblin1->hp == 0 && goblin2->hp>0)
			{
				goblin2->hpreduce(zardzewialy_miecz->attack2(H->AttackPoints));
			}
			else if (goblin1->hp == 0 && goblin2->hp == 0 && goblin3->hp>0)
			{
				goblin3->hpreduce(zardzewialy_miecz->attack2(H->AttackPoints));
			}
			cout << endl;
			if (goblin1->hp > 0)
			{
				cout << "Tura " << goblin1->name << "a pierwszego" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(goblin1->atak());
				}
				if (random_attack == 1)
				{
					H->hpreduce(goblin1->atak2());

				}
			}
			if (goblin2->hp > 0)
			{
				cout << "Tura " << goblin2->name << "a drugiego" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(goblin2->atak());
				}
				if (random_attack == 1)
				{
					H->hpreduce(goblin2->atak2());

				}
			}
			if (goblin3->hp > 0)
			{
				cout << "Tura " << goblin3->name << "a trzeciego" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(goblin3->atak());
				}
				if (random_attack == 1)
				{
					H->hpreduce(goblin3->atak2());

				}
			}
			break;
		}
		case 'p':
		{
			B->showContent(B->tab);
			break;
		}
		case 'e':
		{
			int przedmiot;
			B->showContent(B->tab);

			do
			{
				cout << "Ktorego przedmiotu chcesz uzyc? " << endl;
				cin >> przedmiot;
			} while (B->tab[przedmiot - 1] == "WOLNE MIEJSCE");

			if (B->tab[przedmiot - 1] == "Maly zwoj leczenia")
			{
				H->gethealed(maly_zwoj->heal(H->heroMana, H->hp, H->maxhp));
				if (maly_zwoj->condition == 0)
				{
					B->removeItem(maly_zwoj->name);
					B->reduceweight(maly_zwoj->weight);
				}
			}
			if (goblin->hp > 0)
			{
				cout << "Tura " << goblin->name << "a" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(goblin->atak());
				}
				if (random_attack == 1)
				{
					H->hpreduce(goblin->atak2());
					break;
				}
			}
			break;
		}
		}
	}
	cout << "Ostatni goblin pada. Czujesz triumf i zarazem zmeczenie " << endl;
	cout << "Po dwoch meczacych walkach czujesz sie pewniejszy i silniejszy " << endl;
	cout << "Zyskujesz POZIOM 2" << endl;
	H->poziom = 2;
	H->levelup();
	H->wyswietl_staty();
	cout << "Na ostatnim zabitym goblinie dostrzegasz swiecaca kolczuge. Podnosisz ja." << endl;
	ArmorItem * zbroja = new ArmorItem();
	zbroja->showStats();
	cout << "Czy chcesz ja teraz zalozyc? y/n " << endl;
	cin >> zalozyc;
	if (zalozyc == 'y')
	{
		H->Defense += zbroja->defensePoints;
	}
	else
	{
		B->addItem(zbroja->name);
		B->addweight(zbroja->weight);
		cout << "Przedmiot " << zbroja->name << " schowano do plecaka " << endl;
		B->showContent(B->tab);
	}

	cout << "Idac przed siebie w glab jaskini, slyszysz coraz mocniejsze, masywne kroki nieznanej Ci postaci " << endl;
	cout << "Wchodzac do glebszego pomieszczenia, widzisz wielka sylwetke potwora " << endl;
	cout << "Twoim oczom ukazuje sie Troll Jaskiniowy! " << endl;
	cout << "Rozpoczynanie walki 3" << endl;

	Troll * troll = new Troll;
	while (instrukcja != 'q')
	{
		if (H->hp == 0)
		{
			instrukcja == 'q';
			cout << "Nie zyjesz. Przegrales " << endl;
			break;
		}
		cout << endl;
		cout << "Stan rozgrywki 1.3 (POZIOM/WALKA) " << endl;
		cout << endl;
		cout << "Twoje zycie: " << H->hp << "/" << H->maxhp << endl;
		cout << endl;
		cout << "Zycie przeciwnika " << troll->hp << "/" << troll->maxhp << endl;
		cout << endl;
		if (troll->hp == 0)
		{
			instrukcja == 'q';
			break;
		}
		cout << "Wcisnij a, aby zaatakowac przeciwnika zwyklym atakiem (" << zardzewialy_miecz->accuracy << " % szans)" << endl;
		cout << "Wcisnij z, aby zaatakowac przeciwnika silniejszym atakiem (" << zardzewialy_miecz->accuracy2 << " % szans)" << endl;
		cout << "Wcisnij e, aby uzyc przedmiotu " << endl;
		cout << "Wcisnij p, aby wyswietlic zawartosc plecaka " << endl;

		cin >> instrukcja;

		switch (instrukcja)
		{
		case 'a':
		{
			cout << "zwykly atak" << endl;
			troll->hpreduce(zardzewialy_miecz->attack(H->AttackPoints));
			cout << endl;
			if (troll->hp > 0)
			{
				cout << "Tura " << troll->name << "a" << endl;
				H->hpreduce(troll->atak());
			}
			if (H->hp != 0)
			{
				H->hp += zbroja->regen();
				H->checkhp();
			}
			else
			{
				instrukcja == 'q';
				break;
			}
			break;
		}
		case 'z':
		{
			cout << "silniejszy atak" << endl;
			troll->hpreduce(zardzewialy_miecz->attack2(H->AttackPoints));
			cout << endl;
			if (troll->hp > 0)
			{
				cout << "Tura " << troll->name << "a" << endl;
				H->hpreduce(troll->atak());
			}
			if (H->hp != 0)
			{
				H->hp += zbroja->regen();
				H->checkhp();
			}
			else
			{
				instrukcja == 'q';
				break;
			}

			break;
		}
		case 'p':
		{
			B->showContent(B->tab);
			break;
		}
		case 'e':
		{
			int przedmiot;
			B->showContent(B->tab);

			do
			{
				cout << "Ktorego przedmiotu chcesz uzyc? " << endl;
				cin >> przedmiot;
			} while (B->tab[przedmiot - 1] == "WOLNE MIEJSCE");

			if (B->tab[przedmiot - 1] == "Maly zwoj leczenia")
			{
				H->gethealed(maly_zwoj->heal(H->heroMana, H->hp, H->maxhp));
				if (maly_zwoj->condition == 0)
				{
					B->removeItem(maly_zwoj->name);
					B->reduceweight(maly_zwoj->weight);
				}
			}
			if (troll->hp > 0)
			{
				cout << "Tura " << troll->name << "a" << endl;

				H->hpreduce(troll->atak());
			}
			if (H->hp != 0)
			{
				H->hp += zbroja->regen();
				H->checkhp();
			}
			else
			{
				instrukcja == 'q';
				break;
			}
			break;
		}
		}
	}
	cout << "Upadek trolla jaskiniowego spowodowal niesamowity halas." << endl;
	cout << "Pokonanie tak wielkiego przeciwnika dodalo Ci wiary i pewnosci siebie " << endl;
	cout << "Zyskujesz POZIOM 3 " << endl;
	H->poziom = 3;
	H->levelup();
	H->wyswietl_staty();
	cout << "Kolo zabitego przeciwnika dostrzegasz Kolczasty Obuch " << endl;
	WeaponItem * obuch = new WeaponItem(2);
	obuch->showStats();
	cout << "Czy chcesz go teraz zalozyc? y/n " << endl;
	cin >> zalozyc;
	if (zalozyc == 'y')
	{
		zardzewialy_miecz->equipped = false;
		B->addItem(zardzewialy_miecz->name);
		B->addweight(zardzewialy_miecz->weight);
		obuch->equipped = true;
		H->Strength += 5;
		H->AttackPoints = 1.5*H->Strength;
		cout << "Twoja bron to teraz " << obuch->name << endl;
		cout << "Przedmiot " << zardzewialy_miecz->name << " schowano do plecaka " << endl;
		B->showContent(B->tab);
	}
	else
	{
		B->addItem(obuch->name);
		B->addweight(obuch->weight);
		cout << "Przedmiot " << obuch->name << " schowano do plecaka " << endl;
		B->showContent(B->tab);
	}
	MagicItem * duzy_zwoj = new MagicItem(5);
	cout << "Znalazles duzy zwoj leczenia! " << endl;
	cout << "Uzyj w walce, aby zyskac 50 punktow hp " << endl;
	B->addItem(duzy_zwoj->name);
	B->addweight(duzy_zwoj->weight);
	B->showContent(B->tab);
	cout << "Czujesz, ze Krol Goblinow jest juz blisko. " << endl;
	cout << "Splamiony krwia trolla jaskiniowego przemierzasz jaskinie w poszukiwaniu Krola Goblinow " << endl;
	cout << "Czujesz, ze walka jest nieunikniona " << endl;
	cout << "Wchodzisz do wielkiego pomieszczenia, ktore oswietla kilkanascie pochodni " << endl;
	cout << "Na srodku widzisz tron, na tronie masywna postac " << endl;
	cout << "Smiech Krola Goblinow tylko Cie rozwscieczyl " << endl;
	cout << "Kiedy wstal z tronu, przyjal pozycje bojowa " << endl;
	cout << "Ty tez byles gotowy... " << endl;
	Goblin * krol = new Goblin(100);
	while (instrukcja != 'q')
	{
		if (H->hp == 0)
		{
			instrukcja == 'q';
			cout << "Nie zyjesz. Przegrales " << endl;
			break;
		}
		if (krol->hp == 0)
		{
			cout << "Krol Goblinow ginie! " << endl;
			instrukcja == 'q';
			break;

		}
		cout << endl;
		cout << "Stan rozgrywki 1.4 (POZIOM/WALKA) " << endl;
		cout << endl;
		cout << "Twoje zycie: " << H->hp << "/" << H->maxhp << endl;
		cout << endl;
		cout << "Zycie przeciwnika " << krol->hp << "/" << krol->maxhp << endl;
		cout << endl;
		if (krol->hp == 0)
		{
			instrukcja == 'q';
			break;
		}
		cout << "Wcisnij a, aby zaatakowac przeciwnika zwyklym atakiem (" << obuch->accuracy << " % szans)" << endl;
		cout << "Wcisnij z, aby zaatakowac przeciwnika silniejszym atakiem (" << obuch->accuracy2 << " % szans)" << endl;
		cout << "Wcisnij e, aby uzyc przedmiotu " << endl;
		cout << "Wcisnij p, aby wyswietlic zawartosc plecaka " << endl;

		cin >> instrukcja;

		switch (instrukcja)
		{
		case 'a':
		{
			cout << "zwykly atak" << endl;
			krol->hpreduce(obuch->attack(H->AttackPoints));
			cout << endl;
			if (krol->hp > 0)
			{
				cout << "Tura Krola Goblinow" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(krol->atak());
					if (H->hp != 0)
					{
						H->hp += zbroja->regen();
						H->checkhp();
					}
					else
					{
						instrukcja == 'q';
						break;
					}
				}
				if (random_attack == 1)
				{
					H->hpreduce(krol->atak2());
					if (H->hp != 0)
					{
						H->hp += zbroja->regen();
						H->checkhp();
					}
					else
					{
						instrukcja == 'q';
						break;
					}
					break;
				}
			}
			break;
		}
		case 'z':
		{
			cout << "silniejszy atak" << endl;
			krol->hpreduce(obuch->attack2(H->AttackPoints));
			cout << endl;
			if (krol->hp > 0)
			{
				cout << "Tura Krola Goblinow" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(krol->atak());
					if (H->hp != 0)
					{
						H->hp += zbroja->regen();
						H->checkhp();
					}
					else
					{
						instrukcja == 'q';
						break;
					}
				}
				if (random_attack == 1)
				{
					H->hpreduce(krol->atak2());
					if (H->hp != 0)
					{
						H->hp += zbroja->regen();
						H->checkhp();
					}
					else
					{
						instrukcja == 'q';
						break;
					}
					break;
				}
			}
			break;
		}
		case 'p':
		{
			B->showContent(B->tab);
			break;
		}
		case 'e':
		{
			int przedmiot;
			B->showContent(B->tab);

			do
			{
				cout << "Ktorego przedmiotu chcesz uzyc? " << endl;
				cin >> przedmiot;
			} while (B->tab[przedmiot - 1] == "WOLNE MIEJSCE");

			if (B->tab[przedmiot - 1] == "Maly zwoj leczenia")
			{
				H->gethealed(maly_zwoj->heal(H->heroMana, H->hp, H->maxhp));
				if (maly_zwoj->condition == 0)
				{
					B->removeItem(maly_zwoj->name);
					B->reduceweight(maly_zwoj->weight);
				}
			}
			if (B->tab[przedmiot - 1] == "Duzy zwoj leczenia")
			{
				H->gethealed(duzy_zwoj->heal(H->heroMana, H->hp, H->maxhp));
				if (duzy_zwoj->condition == 0)
				{
					B->removeItem(duzy_zwoj->name);
					B->reduceweight(duzy_zwoj->weight);
				}
			}
			if (krol->hp > 0)
			{
				cout << "Tura Krola Goblinow" << endl;
				random_attack = rand() % 2;
				if (random_attack == 0)
				{
					H->hpreduce(krol->atak());
					if (H->hp != 0)
					{
						H->hp += zbroja->regen();
						H->checkhp();
					}
					else
					{
						instrukcja == 'q';
						break;
					}
				}
				if (random_attack == 1)
				{
					H->hpreduce(krol->atak2());
					if (H->hp != 0)
					{
						H->hp += zbroja->regen();
						H->checkhp();
					}
					else
					{
						instrukcja == 'q';
						break;
					}
					break;
				}
			}
			break;
		}
		}
	}
	if (H->hp > 0)
	{
		przejscie_gry();
	}

	//	WeaponItem * W = new WeaponItem;
	//	ArmorItem * A = new ArmorItem;
	//ScrollItem * S = new ScrollItem;
	//RuneItem * R = new RuneItem;
	//UniqueWeaponItem * Uw = new UniqueWeaponItem;
	//UniqueArmorItem * Ua = new UniqueArmorItem;

	//W->attack(H->AttackPoints);
	//A->defense(6, H->Defense);
	//S->openPortal(S->travelLength, H->heroMana);
	//R->magicAttack(H->heroMana);
	//Uw->specialAttack(H->AttackPoints);
	//S->getRequiredMana();
	//Uw->getCreator();
	//Ua->getCreator();
	//Ua->getSpecialStats();
	//Ua->SpecialDefense(15, H->Defense);
	//	Ua->MagicCounterAttack(H->heroAura);
	//B->getFull();
	//	B->getSize();

	//B->showContent(B->tab);
	//B->addItem(Uw->name);
	//	B->addItem(Ua->name);
	//	B->setFull(B->tab);
	//	cout << Uw->name << endl;
	//B->showContent(B->tab);
	//B->removeItem(Uw->name);
	//B->showContent(B->tab);
	system("PAUSE");
	return 0;
}



