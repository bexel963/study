package com.my.music;

import java.util.ArrayList;

public class PlayList {
	
	private String name;
	private ArrayList<Song> songs;
	
	PlayList(String name){
		this.name = name;
		this.songs = new ArrayList<Song>();
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	public void addSong(Song s) {
		this.songs.add(s);
	}
	public boolean removeSong(String songName) {
		
		Song song = findSongOrNull(songName);
		if(song == null) {
			return false;
		}
		this.songs.remove(song);
		return true;
	}
	
	public Song findSongOrNull(String songName) {
		for(Song song : this.songs) {
			if(songName.equals(song.getName())) {
				return song;
			}
		}
		return null;
	}
	public void play() {
		System.out.println(String.format("---Play %s---\n", this.name));
		
		for(Song song : songs) {
			song.play();
		}
	}
}

















