terraform {
  required_providers {
    digitalocean = {
      # Digitalocean Paketi https://registry.terraform.io/providers/digitalocean/digitalocean/latest
      source  = "digitalocean/digitalocean"     
    }
  }
}

variable "do_token" {                           
  # Digitalocean Token Değişkeni
  type        = string
}


provider "digitalocean" {                       
  # DigitalOcean paketinin token değişkenine 
  # konsoldan girilen token değerinin aktarılması.
  token = "${var.do_token}"
}


resource "digitalocean_droplet" "virtualMachine" {
 image              = "ubuntu-18-04-x64"                      
  # Image     : Ubuntu  18.04 x64
  # Image Listesi -> https://slugs.do-api.dev/
  name               = "enginVirtualMachine"                  
  # Makina Adı: enginVirtualMachine
  region             = "fra1"                                 
  # Bölge     : Frankfurt, Germany  -> https://docs.digitalocean.com/products/platform/availability-matrix/
  size               = "s-1vcpu-1gb"                          
  # Boyutu    : 1 CPU 1 GB
}

output "droplet_output" {
  value = digitalocean_droplet.virtualMachine                 
  # Oluşturulan sunucuya ait bilgiler konsol ekranına çıktı olarak verilecektir. 
}

