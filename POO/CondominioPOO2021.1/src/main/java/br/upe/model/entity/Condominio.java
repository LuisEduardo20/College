package br.upe.model.entity;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Getter 
@Setter
@Entity
@NoArgsConstructor
@AllArgsConstructor
public class Condominio{
	@Id @GeneratedValue (strategy = GenerationType.IDENTITY)
	private Long id;
	private String nome;
	private String cnpj;
	private String endereco;

}
