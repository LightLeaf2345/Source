using System.Xml.Linq;

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*name & breed
 *if null name Balkan breed Street excellent
 *view + change name
 *dog can bark*/


namespace Lab01
{
    public class Dog
    {
        private string name;
        private string breed;
        public Dog()
        {
            this.name = "Balkan";
            this.breed = "Street excellent";
        }
        public Dog(string name, string breed)
        // mỗi 1 class phải có 1 hàm khởi tạo
        {
            this.name = name;
            this.breed = breed;
        }
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public string Breed { get; set; }
        
        public void Bark()
        {
            Console.WriteLine("Gau gau");
        }
        public void Bark(string type)
        {
            if (type =="husky")
            {
                Console.WriteLine("Gu gu");
            }
            else
            {
                 
            }
        }
            public void ShowYourIdentity()
        {
            string identityInformation = $"Name {this.Name} and Breed {this.Breed}";
            Console.WriteLine(identityInformation);
        }
        /* Alternative for the above
          public void SayBau()
        {
            Console.WriteLine("{0} said Bauuul!", this.name
        }
        */
    } 
}

